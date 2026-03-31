#include <stdio.h>
#include <stdlib.h>

/*
 * AED2 - AP01/AP02
 * Lista duplamente encadeada ordenada com regra de proximidade
 * Saída:
 * 1) IDs ordenados
 * 2) NEP total
 */

typedef struct Node {
    int id;
    struct Node *prev;
    struct Node *next;
} Node;

static Node *new_node(int id) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        exit(1);
    }
    n->id = id;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

static void insert_ordered(Node **head, Node **tail, int id, long long *nep_total) {
    Node *n = new_node(id);
    //rule 1
    if (*head == NULL) {
        *head = n;
        *tail = n;
        return;
    }
    
    //rule 2
    if (id <= (*head)->id) {
        n->next = *head;
        (*head)->prev = n;
        *head = n;
        return;
    }

    //rule 3
    if (id >= (*tail)->id) {
        n->prev = *tail;
        (*tail)->next = n;
        *tail = n;
        return;
    }
    
    //rule 4
    int d_head = abs(id - (*head)->id);
    int d_tail = abs(id - (*tail)->id);

    // Choose the closest side to start the search.
    //rule 5
    if (d_head <= d_tail) {
        Node *cur = *head;

        // Count one NEP per forward move between nodes.
        while (cur->next != NULL && cur->next->id < id) {
            cur = cur->next;
            (*nep_total)++;
        }
        (*nep_total)++;

        n->next = cur->next;
        n->prev = cur;
        cur->next->prev = n;
        cur->next = n;
    } 
    //rule 6
    else {
        Node *cur = *tail;

        // Count one NEP per backward move between nodes. */
        while (cur->prev != NULL && cur->prev->id > id) {
            cur = cur->prev;
            (*nep_total)++;
        }
        (*nep_total)++;

        n->prev = cur->prev;
        n->next = cur;
        cur->prev->next = n;
        cur->prev = n;
    }
}

static void print_list(Node *head) {
    Node *cur = head;
    int first = 1;

    while (cur != NULL) {
        if (!first) {
            printf(" ");
        }
        printf("%d", cur->id);
        first = 0;
        cur = cur->next;
    }
    printf("\n");
}

static void free_list(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    Node *head = NULL;
    Node *tail = NULL;
    long long nep_total = 0;

    for (int i = 0; i < n; i++) {
        int id;
        if (scanf("%d", &id) != 1) {
            free_list(head);
            return 0;
        }
        insert_ordered(&head, &tail, id, &nep_total);
    }

    print_list(head);
    printf("%lld\n", nep_total);

    free_list(head);
    return 0;
}
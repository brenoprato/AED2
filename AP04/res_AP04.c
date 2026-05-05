/*
 * AED2 2026 - AP04 - HeapSort com filtro de densidade
 *
 * Entrada: N, K e N palavras minusculas
 * Saida:
 * 1) Avisos para palavras invalidas
 * 2) Heap inicial apos build_heap
 * 3) Palavras validas ordenadas por HeapSort
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_SIZE 21

typedef struct {
    char text[MAX_WORD_SIZE];
    int weight;
} Word;

static int char_index(char c) {
    return c - 'a';
}

static int calculate_weight(const char *text, int *frequency) {
    int weight = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        weight += frequency[char_index(text[i])];
    }

    return weight;
}

static int is_valid_word(const char *text, int *frequency, int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (frequency[char_index(text[i])] < k) {
            return 0;
        }
    }

    return 1;
}

// Returns 1 if 'a' must be above 'b' in the max heap.
static int is_greater(Word a, Word b) {
    if (a.weight != b.weight) {
        return a.weight > b.weight;
    }

    return strcmp(a.text, b.text) > 0;
}

static void swap_words(Word *words, int idx_a, int idx_b) {
    if (idx_a == idx_b) {
        return;
    }

    Word temp = words[idx_a];
    words[idx_a] = words[idx_b];
    words[idx_b] = temp;
}

static void max_heapify(Word *words, int heap_size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap_size && is_greater(words[left], words[largest])) {
        largest = left;
    }

    if (right < heap_size && is_greater(words[right], words[largest])) {
        largest = right;
    }

    if (largest != index) {
        swap_words(words, index, largest);
        max_heapify(words, heap_size, largest);
    }
}

static void build_max_heap(Word *words, int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        max_heapify(words, heap_size, i);
    }
}



static void print_words(const char *label, Word *words, int n) {
    printf("%s", label);

    for (int i = 0; i < n; i++) {
        printf(" %s", words[i].text);
    }

    printf("\n");
}

int main(void) {
    int n;
    int k;

    if (scanf("%d %d", &n, &k) != 2) {
        return 0;
    }

    Word *words = (Word *)malloc(n * sizeof(Word));
    if (words == NULL) {
        return 1;
    }

    int frequency[ALPHABET_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        if (scanf("%20s", words[i].text) != 1) {
            free(words);
            return 0;
        }

        words[i].weight = 0;
        for (int j = 0; words[i].text[j] != '\0'; j++) {
            frequency[char_index(words[i].text[j])]++;
        }
    }

    int valid_count = 0;

    for (int i = 0; i < n; i++) {
        if (is_valid_word(words[i].text, frequency, k)) {
            words[i].weight = calculate_weight(words[i].text, frequency);
            words[valid_count] = words[i];
            valid_count++;
        } else {
            printf("A palavra %s eh invalida (K=%d)\n", words[i].text, k);
        }
    }

    if (valid_count == 0) {
        printf("Erro: Sem palavras validas para ordenacao.\n");
        free(words);
        return 0;
    }

    build_max_heap(words, valid_count);
    print_words("build_heap:", words, valid_count);

    for (int i = valid_count - 1; i > 0; i--) {
        swap_words(words, 0, i);
        max_heapify(words, i, 0);
    }

    print_words("palavras:", words, valid_count);

    free(words);
    return 0;
}
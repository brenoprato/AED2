#include <stdio.h>
#include <stdlib.h>

/*
 * AED2 - AP02
 * Merge Sort com contagem de quedas drasticas
 * Entrada: N e N inteiros
 * Saida:
 * 1) Total de quedas drasticas (V[i] > 2 * V[j] com i < j)
 * 2) Vetor ordenado de forma crescente
 */

static void merge(int *arr, int *temp, int left, int mid, int right, long long *drastic_falls) {
    int i = left;
    int j = mid + 1;
    int k = left;

    // Contar quedas drasticas: elementos da esquerda > 2 * elementos da direita
    // Como ambas as metades estao ordenadas, usamos dois ponteiros
    int idx = left;
    for (int r = mid + 1; r <= right; r++) {
        // Encontrar o primeiro elemento da esquerda que satisfaz arr[idx] > 2 * arr[r]
        // Como a esquerda esta ordenada, todos os elementos apos idx tambem satisfazem
        while (idx <= mid && (long long)arr[idx] <= 2LL * arr[r]) {
            idx++;
        }
        // Todos os elementos de idx ate mid satisfazem a condicao
        *drastic_falls += (mid - idx + 1);
    }

    // Merge padrao do merge sort
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copiar de volta para o array original
    for (int l = left; l <= right; l++) {
        arr[l] = temp[l];
    }
}

static void merge_sort(int *arr, int *temp, int left, int right, long long *drastic_falls) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, temp, left, mid, drastic_falls);
        merge_sort(arr, temp, mid + 1, right, drastic_falls);
        merge(arr, temp, left, mid, right, drastic_falls);
    }
}

static void print_array(int *arr, int n) {
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (!first) {
            printf(" ");
        }
        printf("%d", arr[i]);
        first = 0;
    }
    printf("\n");
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL || temp == NULL) {
        free(arr);
        free(temp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            free(temp);
            return 0;
        }
    }

    long long drastic_falls = 0;
    merge_sort(arr, temp, 0, n - 1, &drastic_falls);

    printf("%lld\n", drastic_falls);
    print_array(arr, n);

    free(arr);
    free(temp);
    return 0;
}
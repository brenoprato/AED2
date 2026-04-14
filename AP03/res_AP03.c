/*
 * AED2 2026 (1S) - AP03 - QuickSort
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int gravity;
} Patient;

long long int swapCount = 0;

// Returns 1 if 'a' has higher priority than 'b'
int priority(Patient a, Patient b) {
    if (a.gravity != b.gravity)
        return a.gravity > b.gravity;
    return a.id < b.id;
}

void swap(Patient *A, int idxA, int idxB) {
    if (idxA == idxB) return;
    if (A[idxA].id == A[idxB].id && A[idxA].gravity == A[idxB].gravity) return;

    Patient temp = A[idxA];
    A[idxA] = A[idxB];
    A[idxB] = temp;
    swapCount++;
}

void medianOfThree(Patient *A, int p, int r) {
    int mid = p + (r - p) / 2;

    if (priority(A[mid], A[p]))
        swap(A, mid, p);

    if (priority(A[r], A[p]))
        swap(A, r, p);

    if (priority(A[r], A[mid]))
        swap(A, r, mid);

    // Place median (pivot) at A[r]
    swap(A, mid, r);
}

int partition(Patient *A, int p, int r) {
    medianOfThree(A, p, r);

    Patient pivot = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (priority(A[j], pivot)) {
            i++;
            swap(A, i, j);
        }
    }

    swap(A, i + 1, r);
    return i + 1;
}

void quickSort(Patient *A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Patient *patients = (Patient *)malloc(n * sizeof(Patient));

    for (int i = 0; i < n; i++)
        scanf("%d %d", &patients[i].id, &patients[i].gravity);

    quickSort(patients, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", patients[i].id);

    printf("Swaps: %lld\n", swapCount);

    free(patients);
    return 0;
}
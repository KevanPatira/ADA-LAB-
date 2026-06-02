#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge(int low, int mid, int high, int *a) {

    int i = low;
    int j = mid + 1;
    int k = low;

    int temp[high + 1];

    // Merge two sorted halves
    while (i <= mid && j <= high) {

        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Remaining elements
    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    // Copy back
    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int low, int high, int *a) {

    // Base condition
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(low, mid, a);
    mergeSort(mid + 1, high, a);

    merge(low, mid, high, a);
}

int main() {

    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];

    // Random array generation
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;

    // Timing start
    clock_t stTime = clock();

    mergeSort(0, n - 1, a);

    // Timing end
    clock_t endTime = clock();

    double t =
        ((double)(endTime - stTime))
        / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nTime Taken: %.4f ms\n", t * 1000);

    return 0;
}

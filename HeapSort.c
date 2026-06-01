#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i){
    int lar =i;
    int left =2*i +1;
    int right= 2*i +2;

    if(left<n && arr[left]>arr[lar]) lar=left;
    if(right<n && arr[right]>arr[lar]) lar=right;

    if(lar != i){
        int t = arr[i];
        arr[i] = arr[lar];
        arr[lar] = t;

        heapify(arr, n, lar);
    }
}

void heapSort(int arr[] , int n){
    for(int i=(n/2) -1;i>=0;i--) heapify(arr, n, i);
    for(int i=n-1;i>0;i++){
        int t=arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integer elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\nTime taken: %f seconds\n", time_taken);
}

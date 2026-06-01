#include<stdlib.h>
#include <stdio.h>
#include <time.h>

void merge (int low,int mid,int high, int *a){
    int i=low, j=mid+1,k=low;
    int arr[high+1];
    while(i<=mid && j<= high){
        if(a[i]< a[j])  arr[k++]=a[i++];
        else    arr[k++]=a[j++];
    }

    while(i<=mid) arr[k++]=a[i++];
    while(j<=high) arr[k++]=a[j++];

    for(i=low;i<=high;i++)  a[i]=arr[i];
}

void mergeSort(int low,int high, int *a){
    if(low == high) return;

    int mid =(low + high)/2;
    mergeSort(low,mid,a);
    mergeSort(mid+1,high,a);
    merge(low, mid, high, a);
}

int main(){
    int n;
    printf("Enter size :");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n;i++)
        a[i]=rand();
        //scanf("%d",&a[i]);

    double stTime =clock();
    mergeSort(0,n-1,a);
    double endTime =clock();
    double t= (endTime -stTime)/CLOCKS_PER_SEC;
    // =printf("Sorted Array :\n");
    // for(int i=0;i<n;i++)    
    //     printf("%d\t",a[i]);
    printf("Time Taken: %.4f ms",t*1000);
    return 0;
}
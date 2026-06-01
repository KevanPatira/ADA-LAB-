#include <stdio.h>
#define MAX 15

struct item{
    char name;
    int profit;
    int wt;
    float ratio;
}a[MAX];

void swap(struct item *a, int i, int j){
    int t[2];char ch;float f;
    t[0]=a[i].profit;
    t[1]=a[i].wt;
    ch = a[i].name;
    f=a[i].ratio;

    a[i].profit = a[j].profit;
    a[i].wt = a[j].wt;
    a[i].ratio = a[j].ratio;
    a[i].name = a[j].name;

    a[j].name = ch;
    a[j].profit = t[0];
    a[j].wt = t[1];
    a[j].ratio = f;
}

int sort(struct item* a,int st,int end){
    float p=a[st].ratio;
    int i=st,j=end;
    while (1) {
        while (i <= end && a[i].ratio >= p) i++;
        while (j >= st && a[j].ratio < p) j--;
        if (i >= j) break;
        swap(a, i, j);
    }
    swap(a,st,j);
    return j;
}

void quickSort(struct item* a,int st,int end ){
    if(st >= end) return;

    int mid = sort(a,st,end);
    quickSort(a,st,mid-1);
    quickSort(a,mid+1,end);
}

void fillUp(struct item* a, int cap, int n){
    quickSort(a,0, n-1);
    float pro=0.0;
    for(int i=0;i<n && cap>0 ; i++){
        if(cap- a[i].wt >= 0){
            cap-=a[i].wt;
            pro+= a[i].profit;
        }
        else {
            pro += cap * a[i].ratio; 
            cap=0;
        }
        printf("%c ,",a[i].name);
    }
    printf("\nProfit = %.2f", pro);
}

int main(){
    printf("Enter size:");
    int n;
    scanf("%d",&n);

    printf("Enter wt, profit and name resp :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].wt);
        scanf("%d",&a[i].profit);
        scanf(" %c",&a[i].name);
        a[i].ratio = (float)a[i].profit / a[i].wt;
    }
    int cap;
    printf("\nEnter capacity :");
    scanf("%d",&cap);
    fillUp(a, cap, n);
    return 0;
}
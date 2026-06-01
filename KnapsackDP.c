#include <stdio.h>
int max(int a , int b){
    return (a>b)?a:b;
}
int knapsack(int W, int wt[], int val[], int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
        for(int w=0;w<=W;w++)
            if(i==0 || w==0) dp[i][w]=0;
            else if(wt[i-1]<=w) dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else dp[i][w]= dp[i-1][w];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++)
            printf("%d\t",dp[i][w]);
        printf("\n");
    }
    return dp[n][W];
}

void main(){
    int n, W;
    printf("Enter number of items:");
    scanf("%d",&n);
    printf("Enter max capacity:");
    scanf("%d",&W);
    int val[n];
    int wt[n];
    printf("Enter wt and value for %d items:\n",n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&wt[i], &val[i]);
    printf("Result = %d", knapsack(W, wt, val ,n));
}
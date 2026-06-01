#include <stdio.h>
#define N 10
#define INFI 99999
int min(int a, int b){
    return (a<b)? a: b;
}
void floyd(int d[N][N], int n){
    for (int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
   
    printf("\nUpdated Path :\n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if (d[i][j] == INFI) printf("INF\t");
            else printf("%d\t", d[i][j]);
        printf("\n");
    }
}

void main(){
    int path[N][N];
    int n;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter distance matrix\n(enter -1 for infinity):\n");
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int a;
            scanf("%d",&a);
            if(a==-1) path[i][j] = INFI;
            else path[i][j]= a;
        }
    floyd(path, n);
}
#include <stdio.h>
#define MAX 100
#define INF 999999

int parent[MAX];

int find(int v){
    while(parent[v])
        v = parent[v];
    return v;
}

void kruskal(int cost[MAX][MAX], int n){
    int edges = 0, minCost = 0;

    while(edges < n - 1){
        int min = INF, u = -1, v = -1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(cost[i][j] < min){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }

        int ru = find(u), rv = find(v);

        if(ru != rv){
            parent[rv] = ru;
            printf("%d - %d : %d\n", u, v, min);
            minCost += min;
            edges++;
        }

        cost[u][v] = cost[v][u] = INF;
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main(){
    int n, cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if(i == j || cost[i][j] == 0)
                cost[i][j] = INF;
        }

    kruskal(cost, n);
    return 0;
}
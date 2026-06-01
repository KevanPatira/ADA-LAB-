#include <stdio.h>
#define MAX 100
#define INF 999999

void prims(int cost[MAX][MAX], int n){
    int visited[MAX] = {0}, minCost = 0, edges = 0;
    visited[0] = 1;

    while (edges < n - 1){
        int min = INF, u, v;
        for (int i = 0; i < n; i++)
            if (visited[i])
                for (int j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min){
                        min = cost[i][j]; u = i; v = j;
                    }

        printf("%d - %d : %d\n", u, v, min);
        minCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("Minimum Cost = %d\n", minCost);
}

void main(){
    int n, cost[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0) cost[i][j] = INF;
        }

    prims(cost, n);
}
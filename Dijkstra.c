#include <stdio.h>
#define V 10;

int minDist(int visited[], int dist[], int n){
    int min = 10000, minIdx = -1;
    for(int v=0;v<n;v++)
        if(!visited[v] && dist[v]<min){
            min= dist[v]; minIdx = v;
        }
    return minIdx;
}

void Dijkstra(int n, int graph[n][n] ,int src){
    int dist[n];
    int visited[n];
    for(int i=0;i<n;i++){
        dist[i]= 10000;
        visited[i]=0;
    }

    dist[src] = 0;
    for(int i=1;i<n;i++){
        int u= minDist(visited, dist , n);
        visited[u] = 1;

        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v] && graph[u][v]+ dist[u] < dist[v])
            dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Vertex\tDistance from Source :\n");
    for(int i=0;i<n;i++) printf("%d\t%d\n", i, dist[i]);

}

void main(){
    int n;
    printf("Enter number of vertex:");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter weights:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    // int graph[n][n] = {
    //     {0, 10, 0, 30, 100},
    //     {10, 0, 50, 0, 0},
    //     {0, 50, 0, 20, 10},
    //     {30, 0, 20, 0, 60},
    //     {100, 0, 10, 60, 0}
    // };
    Dijkstra(n, graph, 0);
}
#include<iostream>
#include<limits>
#define INF INT16_MAX
#define max 100

int minIndex(int dis[max],int vis[max],int V)
{
    int index=-1;
    int min=INF;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0&&dis[i]<min)
        {
            min=dis[i];
            index=i;
        }
    }
    return index;
}
void Dijkstras(int g[max][max],int V,int src)
{
    int vis[max];
    int dis[max];
    for(int i=0;i<V;i++)
    {
        vis[i]=0;
        dis[i]=INF;
    }
    dis[src]=0;
    for(int c=0;c<V-1;c++)
    {
        int u=minIndex(dis,vis,V);
        vis[u]=1;
        if(u==-1) break;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0&&g[u][i]!=INF&&dis[u]!=INF&&(dis[u]+g[u][i])<dis[i])
            {
                dis[i]=dis[u]+g[u][i];
            }
        }
    }
    printf("\nVertex \t\t Shortest Distance from Source (%d)\n", src);
        for (int i = 0; i < V; i++)
        {
            if (dis[i] == INF) {
                printf("%d \t\t INF (Unreachable)\n", i);
            } else {
                printf("%d \t\t %d\n", i, dis[i]);
            }
        }
}
int main() 
{
    int V, E, src;
    int graph[max][max];
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            graph[i][j] = INF;
        }
    }

    // Get graph dimensions
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Read edges
    printf("Enter Edges (source destination and weight) using 0-based indexing:\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; // Assuming it is an undirected map
    }
    printf("Enter the starting node (source): ");
    scanf("%d", &src);
    Dijkstras(graph, V, src);

}
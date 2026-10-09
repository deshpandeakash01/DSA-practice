#include<iostream>
#define max 100
#define INF INT16_MAX
void intializeGraph(int g[max][max],int V)
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            g[i][j]=INF;
        }
    }
}
void readGraph(int g[max][max],int E)// E is number of edges
{
    int u,v,weight;
    printf("enter Edges (source destination and weight) : \n");
    for(int i=0;i<E;i++)
    {
        scanf("%d %d %d",&u,&v,&weight);
        g[u][v]=weight;
        g[v][u]=weight;
    }
}
void primsMST(int g[max][max],int V)
{
    int vis[max]={0};
    int cost=0;
    vis[0]=1;
    for(int c=0;c<V-1;c++)
    {
        int a=-1,b=-1,min=INF;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==1)
            {
                for(int j=0;j<V;j++)
                {
                    if(vis[j]==0&&g[i][j]<min)
                    {
                        min=g[i][j];
                        a=i;b=j;
                    }
                }
            }
        }
        if(a!=-1&&b!=-1)
        {
            cost+=min;
            printf("Edge : %d--%d , cost : %d\n",a,b,min);
            vis[b]=1;
        }
    }
    printf("\n Total cost of minimum spanning tree : %d",cost);

}
int main() {
    int V, E;
    int cost[max][max];
    // Get graph dimensions
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Call the modular functions in sequence
    intializeGraph(cost, V);
    readGraph(cost, E);
    primsMST(cost, V);
}
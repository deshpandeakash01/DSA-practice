#include<iostream>
#define v 4
#define INF INT16_MAX
void printMat(int mat[][v])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(mat[i][j]==INF)
                printf("%7s","INF");
            else{
                printf("%7d",mat[i][j]);
            }
        }
        printf("\n");
    }
}
void floyd(int mat[][v])
{
    int dis[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            dis[i][j]=mat[i][j];
        }
    }
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(dis[i][k]!=INF&&dis[k][j]!=INF)
                {
                    if(dis[i][k]+dis[k][j]<dis[i][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
    }
    printMat(dis);
}
int main() {
    // Let's use the exact same graph from the interactive visualizer
    // 0 on the diagonal means distance to itself is 0.
    int graph[v][v] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    floyd(graph);
    return 0;
}
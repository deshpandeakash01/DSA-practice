#include<iostream>
#define v 5
void topologicalSort(int graph[v][v])
{
    int queue[v];
    int front=0,rear=0,count=0;
    int indegree[v]={0};
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(graph[i][j]!=0) indegree[j]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0) queue[rear++]=i;
    }
    while(front<rear)
    {
        int u=queue[front++];
        printf("%d ",u);
        count++;
        for(int i=0;i<v;i++)
        {
            if(graph[u][i]!=0)
            {
                indegree[i]--;
                if(indegree[i]==0) queue[rear++]=i;
            }
        }
    }
    printf("\n");
    if(count!=v)
            printf("error : cycle exists in graph"); 
}
int main() {
    int graph[v][v]; 
    
    printf("Enter the Adjacency Matrix (%d x %d):\n", v, v);
    printf("(Type 0 for no edge, 1 for an edge)\n");
    
    // Read the matrix row by row, column by column
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]); 
        }
    }
    
    topologicalSort(graph);
    
    return 0; 
}
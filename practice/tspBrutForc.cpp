#include<iostream>
#include<limits.h>
#define INF 1e9
#define N 5
int min=INF;
void tsp(int graph[N][N],int visited[N],int count,int curcity,int cost)
{
    visited[curcity]=1;
    if(count==N)
    {
        if(graph[curcity][0]!=INF)
        {
            cost+=graph[curcity][0];
            if(min>cost)
            { 
                min=cost;
            }
        }
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(visited[i]!=1&&graph[curcity][i]!=INF)
        {
            visited[i]=1;
            tsp(graph,visited,count+1,i,cost+graph[curcity][i]);
            visited[i]=false;
        }
    }
}
int main() {
    // 5x5 distance matrix (INF represents no path)
    int graph[N][N] = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 20},
        {20, 25, 30, 0, 15},
        {25, 30, 20, 15, 0}
    };

    int visited[N] = {0}; // Initialize all as unvisited

    // Start at city 0
    // count starts at 1 because we have visited the first city
    // cost starts at 0
    tsp(graph, visited, 1, 0, 0);

    if (min!= INT_MAX) {
        std::cout << "The minimum path cost is: " << min << std::endl;
    } else {
        std::cout << "No valid path exists." << std::endl;
    }
    return 0;
}
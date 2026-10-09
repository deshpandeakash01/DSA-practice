#include<iostream>
#define N 5
int min=INT16_MAX;
int assign(int cost[N][N],int vis[N],int a,int cc)
{
    if(a==N)
    {
        if(cc<min) min =cc;
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            assign(cost,vis,a+1,cc+cost[a][i]);
            vis[i]=0;
        }
    }
}
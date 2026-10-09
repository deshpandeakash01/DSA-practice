#include<iostream>
#include<algorithm>
struct item
{
    int weight;
    int value;
};

int knapsack(int w,struct item items[],int n,int dp[][100])
{
    if(n==0||w==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1) return dp[n][w];
    else if(items[n-1].weight<=w)
    {
        return dp[n][w]=std::max((items[n-1].value+knapsack(w-items[n-1].weight,items,n-1,dp)),knapsack(w,items,n-1,dp));
    }
    else
    {
        return dp[n][w]=knapsack(w,items,n-1,dp);
    }
}
int main() {
    int capacity = 50;
    int n = 3;
    
    struct item items[] = {
        {10, 60},  // weight, value
        {20, 100},
        {30, 120}
    };
    
    // Create the DP table and fill it entirely with -1
    int dp[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }
    
    int maxValue = knapsack(capacity, items, n, dp);
    printf("Maximum value in 0/1 Knapsack: %d\n", maxValue);
    
    return 0;
}
#include<iostream>
int knapsack(int weights[],int values[],int cap,int n)
{
    if(n==0||cap==0) return 0;
    if(weights[n-1]>cap)
        return knapsack(weights,values,cap,n-1);
    else{
        int include=values[n-1]+knapsack(weights,values,cap-weights[n-1],n-1);
        int exclude=knapsack(weights,values,cap,n-1);
        return std::max(include,exclude);
    }
}
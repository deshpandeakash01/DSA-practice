#include<iostream>
struct item
{
    int value;
    int weight;
    double ratio;
};
double FractionalKnapsack(int w,struct item items[],int n)
{
    for(int i=0;i<n;i++)
    {
        items[i].ratio=items[i].value/items[i].weight;
    }
    //sort
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(items[i].ratio<items[j].ratio) std::swap(items[i],items[j]);
        }
    }
    double cap=w;
    double val=0;
    for(int i=0;i<n;i++)
    {
        if(items[i].weight<=cap)
        {
            val+=items[i].value;
            cap-=items[i].weight;
        }
        else{
            val+=items[i].ratio*cap;
        }
    }
    return val;
}
int main() {
    // Quick test to prove it works
    int capacity = 50;
    struct item items[] = {
        {60, 10, 0.0},
        {100, 20, 0.0},
        {120, 30, 0.0}
    };
    int n = 3;

    double maxValue = FractionalKnapsack(capacity, items, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}
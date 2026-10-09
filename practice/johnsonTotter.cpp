#include<iostream>
#include<algorithm>
#define left -1
#define right 1
struct ele
{
    int val;
    int dir;
};
void printPermutation(struct ele elements[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(elements[i].dir==left)
            printf("%d ",elements[i].val);
        else   
            printf("%d ",elements[i].val);
    }
    printf("\n");
}
int getMobileInde(struct ele elements[],int n)
{
    int mi=-1;
    int max=0;
    for(int i=0;i<n;i++)
    {
        bool isMb=false;
        if(elements[i].dir==left&&i>0)
        {
            if(elements[i].val>elements[i-1].val)
                isMb=true;
        }
        if(elements[i].dir==right&&i<n-1)
        {
            if(elements[i].val>elements[i+1].val)
                isMb=true;
        }
        if(isMb&&elements[i].val>max)
        {
            mi=i;
            max=elements[i].val;
        }
    }
    return mi;
}
void jt(int n)
{
    ele arr[100];
    for(int i=0;i<n;i++)
    {
        arr[i].dir=left;
        arr[i].val=i+1;
    }
    printPermutation(arr,n);
    while(true)
    {
        int mindex=getMobileInde(arr,n);
        int melement=arr[mindex].val;
        if(mindex==-1)break;
        int targetidx=mindex+arr[mindex].dir;
        std::swap(arr[mindex],arr[targetidx]);
        for(int i=0;i<n;i++)
        {
            if(arr[i].val>melement)
                arr[i].dir=-arr[i].dir;
        }
        printPermutation(arr,n);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("\nGenerating permutations for n = %d:\n", n);
    jt(n);
    
    return 0;
}
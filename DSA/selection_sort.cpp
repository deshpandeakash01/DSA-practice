#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(i=0;i<=(n-2);i++)
    {
        int min=i;
        for(j=i+1;j<=(n-1);j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        swap(A[i],A[min]);
    }
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
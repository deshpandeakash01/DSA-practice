#include<iostream>
using namespace std;
int main()
{
    //input
    int n,i,j;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    //sorting
    for(i=(n-1);i>=0;i--)
    {
        int s=0;
        for(j=0;j<i;j++)
        {
            if(A[j]>A[j+1]) 
            {
                swap(A[j],A[j+1]); 
                s++;
            }
        }
        if(s==0) break;
    }
    //display
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
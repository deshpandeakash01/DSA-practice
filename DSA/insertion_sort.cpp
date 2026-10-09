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
    for(i=0;i<n;i++)
    {
        j=i;
        while(j>0&&(A[j-1]>A[j]))
        {
            swap(A[j-1],A[j]);
            j--;
        }
    }
    //display
    for(i=0;i<n;i++)   
    {
        cout<<A[i]<<" ";
    }
}
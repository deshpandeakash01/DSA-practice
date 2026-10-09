#include<iostream>
using namespace std;
int main()
{
    //Array
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    //rotate
    int i=0,j=n-1;
    while(i<=j)
    {
        swap(A[i++],A[j--]);
    }
    //dispaly
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
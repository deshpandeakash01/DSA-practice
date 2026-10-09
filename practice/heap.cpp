#include<iostream>
void heapify(int arr[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n&&arr[left]>arr[largest])
        largest=left;
    if(right<n&&arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        std::swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void shiftup(int arr[],int i)
{
    int parent=(i-1)/2;
    if(i>0&&arr[i]>arr[parent])
    {
        std::swap(arr[i],arr[parent]);
        shiftup(arr,parent);
    }
}
void BuildHeapBU(int arr[],int n)
{
    int lastparent=n/2-1;
    for(int i=lastparent;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void BuildHeapTD(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        shiftup(arr,i);
    }
}

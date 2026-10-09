#include<iostream>
int partion(int arr[],int low,int high)
{
    int p=arr[low],i=low,j=high+1;
    while(i<j)
    {
        do
        {
            i++;
        } while (i<=high&&arr[i]<=p);
        do
        {
            j--;
        } while (arr[j]>p);
        if(i<j)std::swap(arr[i],arr[j]);
        
    }
    std::swap(arr[low],arr[j]);
    return j;
}
void QuickSort(int arr[],int low,int high)
{
    if(low>=high) return;
    int part=partion(arr,low,high);
    QuickSort(arr,low,part-1);
    QuickSort(arr,part+1,high);
}
void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    std::cout<<"enter array size of array :  ";
    std::cin>>n;
    int arr[n];
    std::cout<<"\nenter array : ";
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"\norignal array : ";
    printArray(arr,n);
    QuickSort(arr,0,n-1);
    std::cout<<"\nsorted array : ";
    printArray(arr,n);
}
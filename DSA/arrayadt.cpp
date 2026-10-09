#include<iostream>
struct Array
{
    int *A;
    int size ;
    int length;
};
void display(struct Array arr)
{
    int i;
    printf("elements are\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}
void append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length]=x;
        arr->length++;
    }
}
void insert(struct Array *arr,int index,int x)
{
    int i;
    if(arr->length>=index&&index>=0)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;
}
int Delete(struct Array *arr,int index)
{ 
    int x=arr->A[index];
    if(index>=0&&index<arr->length)
    {
        for(int i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}
int L_search(struct Array arr,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}
int B_search(struct Array arr,int key)
{
    int l=0;
    int h=arr.length-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int get(struct Array arr,int index)
{
    if(index>=0&&index<arr.length)
        return arr.A[index];
}
void set(struct Array *arr,int index,int x)
{
    if(index>=0&&index<arr->length)
        arr->A[index]=x;
}
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
        return min;    
}
int reverse(struct Array *arr)
{
    int i=0,j=arr->length-1;
    while(i<j)
    {
        int temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
        i++;j--;
    }
}
int insertsort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return 0;
    while(arr->A[i]>x&&i>=0)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
void isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            printf("array is not sorted\n");
    }
    printf("is sorted\n");
}
int main()
{
    int n,i;
    struct Array arr;
    printf("size of array\n");
    scanf("%d",&arr.size);
    arr.A=new int[arr.size];
    //A=(int*)malloc(arr.size*sizeof(int));
    printf("enter numbers of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;
    display(arr);
    append(&arr,23);printf("\n");
    display(arr);printf("\n");
    //insert(&arr,3,69);
    display(arr);printf("\n");
    printf("deleted element=%d\n",Delete(&arr,4));
    display(arr);printf("\n");
    printf("key present at index :%d\n",L_search(arr,5));
    printf("key present at index :%d\n",B_search(arr,4));
    printf("element at required index=%d\n",get(arr,5));
    //set(&arr,4,55);
    display(arr);printf("\n");
    printf("max=%d\nmin=%d\n",max(arr),min(arr));
    reverse(&arr);
    display(arr);printf("\n");
    /*insertsort(&arr,12);
    display(arr);printf("\n");
    isSorted(arr);  
}


#include <iostream>
using namespace std;
struct Array {
    int *A;
    int size;
    int length;
};
void display(const Array &arr) {
    cout << "elements are\n";
    for (int i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
}
Array* merge(Array *arr1, Array *arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array;
    arr3->size = arr1->length + arr2->length;
    arr3->length = arr3->size;
    arr3->A = new int[arr3->size];

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    while (i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    return arr3;
}
Array* Union(Array arr1,Array arr2)
{
    int i=0,j=0,k=0;
    Array *arr3=new Array;
    arr3->size=arr1.length+arr2.length;
    arr3->A=new int[arr3->size];
    while(i<arr1.length&&j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j])
            arr3->A[k++]=arr1.A[i++];
        else if(arr2.A[j]<arr1.A[i])
            arr3->A[k++]=arr2.A[j++];
        else{
            arr3->A[k++]=arr2.A[j++];
            i++;
        }
    }
    for(;i<arr1.length;i++)
        arr3->A[k++]=arr1.A[i];
    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];
    arr3->length=k;
return arr3;
}
Array* intersection(Array arr1,Array arr2)
{
    int i=0,j=0,k=0;
    Array *arr3=new Array;
    arr3->size=arr1.length+arr2.length;
    arr3->A=new int[arr3->size];
    while(i<arr1.length&&j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j])i++;
        else if(arr2.A[j]<arr1.A[i])j++;
        else{
            arr3->A[k++]=arr2.A[j++];
            i++;
        }
    }
arr3->length=k;
return arr3;
}
Array* diffrence(Array arr1,Array arr2)
{
    int i=0,j=0,k=0;
    Array *arr3=new Array;
    arr3->size=arr1.length+arr2.length;
    arr3->A=new int[arr3->size];
    while(i<arr1.length&&j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j])
            arr3->A[k++]=arr1.A[i++];
        else if(arr2.A[j]<arr1.A[i])j++;
        else{i++;j++;}
    }
    for(;i<arr1.length;i++)
        arr3->A[k++]=arr1.A[i];
    arr3->length=k;
return arr3;
}
int main() 
{
    Array arr1 = { new int[10]{12, 22, 34, 44, 56, 67}, 10, 6 };
    Array arr2 = { new int[10]{11, 22, 33, 44}, 10, 4 };

    Array *arr3 = merge(&arr1, &arr2);
    display(*arr3);printf("\n");
    Array *arr4=Union( arr1,arr2);
    display(*arr4);printf("\n");
    Array *arr5=intersection(arr1,arr2);
    display(*arr5);printf("\n");
    Array *arr6=diffrence(arr1,arr2);
    display(*arr6);printf("\n");
}

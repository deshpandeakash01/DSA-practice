#include<iostream>
int main()
{
    int A[12]={1,4,3,4,2,2,14,6,8,1,1,8};
    int H[15]={0};
    for(int i=0;i<12;i++)
    {
        H[A[i]]++;
    }
    for(int i=1;i<15;i++)
    {
        if(H[i]>1)
        {
            printf("%d is present %d times \n",i,H[i]);
        }
    }
}
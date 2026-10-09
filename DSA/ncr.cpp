#include<iostream>
 int combination(int n,int r)
 {
    if(r==0||n==r)
    {
        return 1;
    }
    else
    {
        return combination(n-1,r-1)+combination(n-1,r);
    }
 }
 int main()
 {
    int x=combination(4,2);
    printf("%d\n",x);
 }
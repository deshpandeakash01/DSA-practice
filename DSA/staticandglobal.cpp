#include<iostream>
using namespace std;
int fun1(int n)
{
    if(n>0)
    {
        return fun1(n-1)+n;
    }
    return 0;
}
int fun2(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun2(n-1)+x;
    }
    return 0;       
}
int fun3(int n)
{
    if(n>0)
    {
        return fun3(n-1)+n;
    }
    return 1;
}
int main()
{
    printf("%d",fun1(5));cout<<endl;
    printf("%d",fun2(5));cout<<endl;
    printf("%d",fun3(5));cout<<endl;
    
}
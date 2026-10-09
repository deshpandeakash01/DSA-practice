#include<iostream>
int fun(int n)
{
    if(n>100)
        return n-10;
    else
        return fun(fun(n+11));
}
int main()
{
    int r=fun(23);
    std::cout<<r;
}
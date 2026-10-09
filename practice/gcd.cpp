#include<iostream>
int gcd_recursive(int a,int b)
{
    if(b==0) return a;
    else return gcd_recursive(b,a%b);
}
int gcd_iterative(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a,b;
    std::cout<<"Enter two numbers : ";
    std::cin>> a >> b;
    int r1=gcd_recursive(a,b);
    int r2=gcd_iterative(a,b);
    std::cout<<r1<<" "<<r2;
}
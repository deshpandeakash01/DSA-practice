#include<iostream>
void fun(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun(n-1);
    }

}
void fun1(int n)
{
    if(n>0)
    {
    fun1(n-1);
    std::cout<<n<<" ";
    }
} 
int fact(int n)
{
    if (n>0)
    {
        return n*fact(n-1);
    }
    return 1;
}
int main()
{
    fun(4);
    std::cout<<std::endl;
    fun1(4);
    std::cout<<std::endl;
    std::cout<<fact(5);
}
#include<iostream>
void fun(int n)
{
    if(n>0)
    {
        for(int i=0;i<n;i++){
            std::cout<<i<<" ";
        }
        fun(n-1);
    }
}
int main()
{
    fun(3);

}
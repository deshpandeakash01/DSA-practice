#include<iostream>
struct complex
{
    int real;
    int imaginary;
    char x;
};
int main()
{
    struct complex c={1,4,'A'};
    std::cout<<sizeof(c)<<std::endl;
    std::cout<<c.real<<"+i"<<c.imaginary;
     
}
// It is easy for machine to read 4 bytes at a time called padding of memory
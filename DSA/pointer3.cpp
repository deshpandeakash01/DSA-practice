// pointer to a structure
#include<iostream>
struct complex
{
    int real;
    int imaginary;
};
int main()
{
    complex c={10,5};
    complex *p=&c;
    std::cout<<c.real<<"+i"<<c.imaginary<<std::endl;
    (*p).real=5;
    (*p).imaginary=10;
    std::cout<<c.real<<"+i"<<c.imaginary<<std::endl;
    p->real=12;
    p->imaginary=24;
    std::cout<<c.real<<"+i"<<c.imaginary<<std::endl;
    std::cout<<sizeof(p)<<std::endl;
    std::cout<<sizeof(*p)<<std::endl;
}
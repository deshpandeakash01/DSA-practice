#include<iostream>
struct complex
{
    int real;
    int imaginary;
    char x;
};
int main()
{
    int A[3];
    int *p=A;
    std::cout<<p<<std::endl;
    std::cout<<*p<<std::endl;
    p=(int *)malloc(3*sizeof(int));
    for(int x:A)
    {
        std::cout<<x<<",";
    }
    std::cout<<sizeof(p)<<std::endl;
    float *a;
    int *b;
    char *c;
    double *d;
    struct complex *e;
    std::cout<<sizeof(a)<<std::endl;
    std::cout<<sizeof(b)<<std::endl;
    std::cout<<sizeof(c)<<std::endl;
    std::cout<<sizeof(d)<<std::endl;
    std::cout<<sizeof(e)<<std::endl;
}   
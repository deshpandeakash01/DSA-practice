#include<iostream>
using namespace std;
struct Rectangle
{
 int lenght;
 int breadth;
};

int area(struct Rectangle r)
{
    return r.lenght*r.breadth;
}
int perimeter(struct Rectangle r)
{
    int p=2*(r.lenght+r.breadth);
    return p;
}
int main()
{
    Rectangle r={20,35}; 
    int A=area(r);
    int P=perimeter(r);
    cout<<A<<","<<P<<endl;
}
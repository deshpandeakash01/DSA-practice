#include<iostream>
using namespace std;
class Rectangle // if u use struct no need of public.
{
public: 
 int lenght;
 int breadth;
int area()
{
    return lenght*breadth;
}
int perimeter()
{
    int p=2*(lenght+breadth);
    return p;
}
};
int main()
{
    Rectangle r={22,35};
    int A=r.area();
    int P=r.perimeter();
    cout<<A<<","<<P<<endl;
}arr
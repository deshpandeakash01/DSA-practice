#include<iostream>
using namespace std;
class Rectangle
{
private:
    int lenght;
    int breadth;
public:
    Rectangle()
    {
        lenght=0;
        breadth=0;
    }
    Rectangle(int l,int b)
    {
        lenght=l;
        breadth=b;
    }
    int area()
    {
        return lenght*breadth;
    }
    int perimeter()
    {
        return 2*(lenght+breadth);
    }
    void setlenght(int l)
    {
        lenght = l;
    }
    void setbreadth(int b)
    {
        breadth = b;
    }
    int getlenght()
    {
        return lenght;
    }
    ~Rectangle()
    {
        cout<<"DESTROYED";
    }


};
int main()
{
    Rectangle r(10,50);
    cout<<"Area="<<r.area()<<endl;
    cout<<"Perimeter="<<r.perimeter()<<endl;
    cout<<"lenght="<<r.getlenght()<<endl;
}
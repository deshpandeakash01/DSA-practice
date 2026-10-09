#include<iostream>
using namespace std;
int area(int lenght,int breadth)
{
    return lenght*breadth;
}
int perimeter(int lenght,int breadth)
{
    int p=2*(lenght+breadth);
    return p;
}
int main()
{
    int lenght,breadth;
    std::cin>>lenght>>breadth;
    int A=area(lenght,breadth);
    int P=perimeter(lenght,breadth);
    cout<<A<<","<<P<<endl;
}
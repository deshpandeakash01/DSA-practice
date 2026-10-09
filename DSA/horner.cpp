#include <iostream>
using namespace std;

double e(int x, int n)
{
    double s = 1;
    for (;n>0;n--)
    {
        s = 1+(x*s)/n;
    }
    return s;
}

int main()
{
    double a = e(1, 10);
    cout <<a<< endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double I(double a, double b, double eps, double(*f)(double)) 
{
    double s = f((b + a) / 2), s1 = 0, s2, h = b - a;
    s2 = s * h;
    while (fabs(s1 - s2) > eps) 
    {
        s = 0;
        h /= 2;
        double a1 = a;
        double b1 = a+h;
        s += f((b1 + a1) / 2);
        while (b1 < b)
        {
            a1 += h;
            b1 += h;
            s += f((b1 + a1) / 2);
        }
        s1 = s2;
        s2 = s * h;
    }
    return s2;
}

double f1(double x)
{
    return x * x * x * x;
}

double f2(double x)
{
    return x * x - 5 * x;
}

double f3(double x)
{
    return 1/x;
}

void main()
{
    int funcnum;
    double a, b, eps;
    cout << "insert a, b, eps, func number" << endl;
    cin >> a >> b >> eps >> funcnum;
    if (funcnum == 1)
    {
        cout << I(a, b, eps, f1);
    }
    else if (funcnum == 2)
    {
        cout << I(a, b, eps, f2);
    }
    else if (funcnum == 3)
    {
        cout << I(a, b, eps, f3);
    }
    else
    {
        cout << "Error!";
    }
}
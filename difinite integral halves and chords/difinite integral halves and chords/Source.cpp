#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double Halves(double a, double b, double epsilon, double(*f)(double))
{
    if (f(a) * f(b) >= 0) 
    {
        cout << "No roots!" << endl;
        return 0;
    }

    double c;
    while ((b - a) >= epsilon) 
    {
        c = (a + b) / 2;

        if (fabs(f(c))<=epsilon) 
        {
            break;
        }
        else if (f(c) * f(a) < 0) 
        {
            b = c;
        }
        else 
        {
            a = c;
        }
    }

    return c;
}

//double Chords(double a, double b, double epsilon, double(*f)(double)) 
//{
//    double x0, x1;
//
//    do 
//    {
//        x0 = a - f(a) * (b - a) / (f(b) - f(a));
//        x1 = b - f(b) * (b - a) / (f(b) - f(a));
//
//        if (f(x0) * f(x1) < 0) 
//        {
//            b = x1;
//        }
//        else 
//        {
//            a = x1;
//        }
//    } while (abs(f(x1)) >= epsilon);
//
//    return x1;
//}

//double Chords(double a, double b, double epsilon, double(*f)(double)) {
//    double x0, x1;
//
//    do {
//        x0 = a - f(a) * (a - b) / (f(a) - f(b));
//        x1 = x0 - f(x0) * (x0 - b) / (f(x0) - f(b));
//
//        if (f(x0) * f(x1) < 0)
//        {
//            b = x1;
//        }
//        else 
//        {
//            a = x1;
//        }
//    } while (abs(a - b) >= epsilon);
//
//    return x1;
//}

double Chords(double a, double b, double eps, double(*f)(double)) 
{
    double x0, x1;

    do 
    {
        x0 = a - f(a) * (b - a) / (f(b) - f(a));
        x1 = a - f(a) * (b - a) / (f(b) - f(a));

        if (f(a) * f(x1) < 0) 
        {
            b = x1;
        }
        else 
        {
            a = x1;
        }

    } while (abs(f(x1)) >= eps);

    return x1;
}

double f1(double x)
{
    return x * x - 1;
}

double f2(double x)
{
    return x-(1-x*x*x*x)/6;
}

double f3(double x)
{
    return x-cos(x);
}

void main()
{
    ifstream fin("in.txt");

    if (!fin.is_open())
    {
        cout << "Error!";
    }

    int funcnum, method;
    double a, b, eps;

    while (fin >> a >> b >> eps >> funcnum >> method)
    {
        switch (funcnum)
        {
        case 1:
            switch (method)
            {
            case 1:
                cout << Halves(a, b, eps, f1);
                break;
            case 2:
                cout << Chords(a, b, eps, f1);
                break;
            default:
                cout << "Invalid input";
            }
            break;
        case 2:
            switch (method)
            {
            case 1:
                cout << Halves(a, b, eps, f2);
                break;
            case 2:
                cout << Chords(a, b, eps, f2);
                break;
            default:
                cout << "Invalid input";
            }
            break;
        case 3:
            switch (method)
            {
            case 1:
                cout << Halves(a, b, eps, f3);
                break;
            case 2:
                cout << Chords(a, b, eps, f3);
                break;
            default:
                cout << "Invalid input";
            }
            break;
        default:
            cout << "Invalid input";
        }
        cout << endl;
    }
}
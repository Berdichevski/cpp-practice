#include <iostream>
#include <cmath>
using namespace std;

double P(double x0, double (*f)(double))
{
	double dx = 1e-3, eps = 1e-9, s = f(x0), prev = 0, cur = (f(x0 + dx) - s) / dx;
	while ((fabs(prev - cur) > eps) && (dx > eps))
	{
		prev = cur;
		dx /= 2;
		cur = (f(x0 + dx) - s) / dx;
	}
	return cur;
}

double P2(double x0, double (*f)(double))
{
	double dx = 1e-3, eps = 1e-9, s = f(x0), prev = 0, cur = ((f(x0 + dx) - 2 * s + f(x0 - dx)) / (dx * dx));

	while ((fabs(prev - cur) > eps) && (dx > eps))
	{
		prev = cur;
		dx /= 2;
		cur = ((f(x0 + dx) - 2 * s + f(x0 - dx)) / (dx * dx));
	}

	if (fabs(cur - prev) <= eps)
	{
		return cur;
	}

	return 0;
}

double F(double a, double b, double eps, double(*f)(double))
{
	double x, x2;
	if (f(a) * P2(a,f) > 0)
	{
		x = a;
	}
	else
	{
		x = b;
	}
	x2 = x - (f(x) / P(x,f));
	while (fabs(x - x2) > eps)
	{
		x = x2;
		x2 = x - (f(x) / P(x,f));
	}
	return x2;
}

double f1(double x)
{
	return x * x * x - 1;
}

double f2(double x)
{
	return x * x - 5;
}

double f3(double x)
{
	return x / 2;
}

int main()
{
	int funcnum;
	double a, b, eps;
	cout << "insert a, b, eps, func number" << endl;
	cin >> a >> b >> eps >> funcnum;
	if (funcnum == 1)
	{
		cout << F(a, b, eps, f1);
	}
	else if (funcnum == 2)
	{
		cout << F(a, b, eps, f2);
	}
	else if (funcnum == 3)
	{
		cout << F(a, b, eps, f3);
	}
	else
	{
		cout << "Error!";
	}
	return 0;
}


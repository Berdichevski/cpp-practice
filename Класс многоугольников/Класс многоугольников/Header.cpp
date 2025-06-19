#include "Header.h"
#include <iostream>
#include <fstream>
using namespace std;

double orientation(const point& a, const point& b, const point& c)
{
	return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

point::point()
{
	this->x = 0.0;
	this->y = 0.0;
}

point::point(int x, int y)
{
	this->x = x;
	this->y = y;
}

void point::copy(const point& p2)
{
	this->x = p2.x;
	this->y = p2.y;
}

double point::distance(point p2)
{
	double dx = p2.x - x;
	double dy = p2.y - y;
	return sqrt(dx * dx + dy * dy);
}

int Polygon::getVerticesAmount()
{
	return verticesAmount;
}

point* Polygon::getVertices()
{
	return vertices;
}


Polygon::Polygon() :verticesAmount(0), vertices(nullptr) {};

Polygon::Polygon(int verticesAmount, point* vertices)
{
	this->verticesAmount = verticesAmount;
	this->vertices = new point[verticesAmount];
	for (int i = 0; i < this->verticesAmount; i++)
	{
		this->vertices[i].copy(vertices[i]);
	}
}

double Polygon::diagonalLength()
{
	double tempDist;
	double maxDist = -1;
	for (int i = 0; i < verticesAmount - 1; i++)
	{
		for (int j = i + 2; j < verticesAmount; j++)
		{
			tempDist = vertices[i].distance(vertices[j]);
			if (tempDist > maxDist)
			{
				maxDist = tempDist;
			}
		}
	}
	return maxDist;
}

double Polygon::perimeter()
{
	double perimeter = 0;
	for (int i = 0; i < verticesAmount - 1; i++)
	{
		perimeter += vertices[i].distance(vertices[i+1]);
	}
	perimeter += vertices[verticesAmount - 1].distance(vertices[0]);
	return perimeter;
}

double Polygon::area()
{
	double area = 0.0;
	for (int i = 0; i < verticesAmount; i++) {
		int j = (i + 1) % verticesAmount;
		area += (vertices[i].x + vertices[j].x) * (vertices[j].y - vertices[i].y);
	}

	area = abs(area) / 2.0;

	return area;
}

bool Polygon::isConvex()
{
	if (verticesAmount < 3) 
	{
		return false;
	} 

	int n = verticesAmount;

	bool allNegative = true;
	bool allPositive = true;

	for (int i = 0; i < n; i++) {
		double ori = orientation(vertices[i], vertices[(i + 1) % n], vertices[(i + 2) % n]);

		if (ori > 0) 
		{
			allNegative = false;
		}
		else if (ori < 0) 
		{
			allPositive = false;
		}

		if (!allNegative && !allPositive) 
		{
			return false;
		}
	}

	return true;
}







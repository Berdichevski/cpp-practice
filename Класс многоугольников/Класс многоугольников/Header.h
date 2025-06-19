#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct point {
    double x;
    double y;
    point();
    point(int x, int y);
    void copy(const point& p2);
    double distance(point p2);
};

class Polygon {
    int verticesAmount;
    point* vertices;
public:
    int getVerticesAmount();
    point* getVertices();
    Polygon();
    Polygon(int verticesAmount, point* vertices);
    double diagonalLength();
    double perimeter();
    double area();
    bool isConvex();
};
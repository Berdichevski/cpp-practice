
/*#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int x1, y1, x2, y2, x0, y0;
    double dis;
    std::cout << "Please type in both coordinates of two points of the line" << "\n";
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << "Please type in both coordinates of the given point" << "\n";
    std::cin >> x0 >> y0;
    dis = abs((y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1) / sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    std::cout << "The distance between the point and the line is " << dis;
}*/

#include <iostream>
#include <cmath>

int x0, y0;

/*double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}*/

double distanceToLine(Point p, Point l1, Point l2) {
    double A = p.x - l1.x;
    double B = p.y - l1.y;
    double C = l2.x - l1.x;
    double D = l2.y - l1.y;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = dot / len_sq;

    double xx, yy;

    if (param < 0) {
        xx = l1.x;
        yy = l1.y;
    }
    else if (param > 1) {
        xx = l2.x;
        yy = l2.y;
    }
    else {
        xx = l1.x + param * C;
        yy = l1.y + param * D;
    }

    return distance(p, { xx, yy });
}

int main() {
    Point p = { 1, 1 };
    Point l1 = { 0, 0 };
    Point l2 = { 2, 0 };

    double dist = distanceToLine(p, l1, l2);

    cout << "Distance from point (" << p.x << ", " << p.y << ") to line segment (" << l1.x << ", " << l1.y << ") - (" << l2.x << ", " << l2.y << ") is " << dist << endl;

    return 0;

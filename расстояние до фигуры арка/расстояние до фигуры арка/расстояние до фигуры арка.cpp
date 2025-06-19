#include <iostream>
#include <cmath>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    double x, y, x1, y1, x2, y2, r, t, dx, dy, proj_x, proj_y, dis, dis1;
    std::cout << "Insert coordinates of the point" << "\n";
    std::cin >> x >> y;
    std::cout << "Insert radius" << "\n";
    std::cin >> r;
    x1 = -r;
    x2 = r;
    y1 = y2 = 0;
    dx = x2 - x1;
    dis1 = pow(99, 88);
    
    if (y > 0)
    {
        if (x > r && y > r)
            dis1 = sqrt(pow(x - 0, 2) + pow(y - 0, 2)) - r;
        else
            dis1 = r - sqrt(pow(x - 0, 2) + pow(y - 0, 2));
    }
    
    t = ((x - x1) * dx + (y - y1) * 0) / (dx * dx + 0 * 0);
    if (t < 0)
    {
        dis = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
    }
    else
    {
        if (t > 1)
        {
            dis = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        }
        else
        {
            proj_x = x1 + t * dx;
            proj_y = y1 + t * 0;
            dis = sqrt(pow(x - proj_x, 2) + pow(y - proj_y, 2));
        }
    }   
    dis = abs(min(dis1,dis));
    std::cout << dis;
}
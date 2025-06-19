#include <iostream>
#include <cmath>

int main()
{
    double x, y, x1, y1, x2, y2, dx, dy, t, proj_x, proj_y;
    std::cout << "Insert coordinates of the point" <<"\n";
    std::cin >> x >> y;
    std::cout << "Insert coordinates of the starting and the ending points of the line" << "\n";
    std::cin >> x1 >> y1 >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx == 0 && dy == 0) 
    {
        std::cout << sqrt(pow(x - x1, 2) + pow(y - y1, 2));
    }
    else
    {
        t = ((x - x1) * dx + (y - y1) * dy) / (dx * dx + dy * dy);
        if (t < 0)
        {
            std::cout << sqrt(pow(x - x1, 2) + pow(y - y1, 2));
        }
        else
            if (t > 1)
            {
                std::cout << sqrt(pow(x - x2, 2) + pow(y - y2, 2));
            }
            else
            {
                proj_x = x1 + t * dx;
                proj_y = y1 + t * dy;
                std::cout << sqrt(pow(x - proj_x, 2) + pow(y - proj_y, 2));
            }
    }
}

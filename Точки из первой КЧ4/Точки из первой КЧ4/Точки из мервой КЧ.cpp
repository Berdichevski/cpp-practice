#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct PointAns
{
    double x;
    double y;
    double dis;
};

void bubbleSortPointAns(PointAns* points, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (points[j].dis > points[j + 1].dis) {
                PointAns temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }
}

int main()
{
    ifstream pointsFile("points.txt"); 
    if (!pointsFile)
    {
        cout << "Couldn't open points.txt\n";
        return 1;
    }

    Point* points;
    points = new Point [1000];

    PointAns* ans_points;
    ans_points = new PointAns[1000];

    int i = 0;
    int j = 0;

    while (pointsFile >> points[i].x >> points[i].y)
    {
//        cout << "Preview: " << points[i].x << " " << points[i].y << endl;

        if ((points[i].x > 0) && (points[i].y > 0))
        {
            ans_points[j].x = points[i].x;
            ans_points[j].y = points[i].y;
            ans_points[j].dis = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
//            cout << '(' << ans_points[j].x << "; " << ans_points[j].y << ')' << " " << ans_points[j].dis << endl;
            j++;
        }
        i++;
    }

//    cout << j << endl;

    pointsFile.close();

    bubbleSortPointAns(ans_points, j);


    std::ofstream file("rightPoints.txt", ios::app);
    if (file.is_open())
    {
        for (int k = 0; k < j; k++)
        {
            file << '(' << ans_points[k].x << "; " << ans_points[k].y << ')' << " " << ans_points[k].dis << endl;
        }
    }
    else {
        cout << "Unable to open file." << endl;
    }
    return 0;
}

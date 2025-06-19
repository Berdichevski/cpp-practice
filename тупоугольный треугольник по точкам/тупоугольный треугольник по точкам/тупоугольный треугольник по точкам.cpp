#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int lenmatr;
	double matrix[100][2];

	cout << "Insert the number of points" << endl;
	cin >> lenmatr;

	for (int i = 0; i < lenmatr; i++)
	{
		cout << "Insert x-coordinate of " << i+1 << " point" << endl;
		cin >> matrix[i][0];
		cout << "Insert y-coordinate of " << i+1 << " point" << endl;
		cin >> matrix[i][1];
	}

/*	for (int i = 0; i < lenmatr; i++)
	{
		cout << matrix[i][0] << matrix[i][1] << endl;
	}*/

//	cout << sqrt(4.0);

	double AB, BC, AC, cABC, cBCA, ABC, BCA, CAB;
	int anglemax = 90;
	int answer1 = 0, answer2 = 0, answer3 = 0;

	for (int i = 0; i < lenmatr; i++)
	{
		for (int j = i+1; j < lenmatr; j++)
		{
			for (int k = j+1; k < lenmatr; k++)
			{
//				cout << matrix[j][0] - matrix[i][0] << endl;
				AB = sqrt((matrix[j][0] - matrix[i][0]) * (matrix[j][0] - matrix[i][0]) + (matrix[j][1] - matrix[i][1]) * (matrix[j][1] - matrix[i][1]));
				BC = sqrt((matrix[k][0] - matrix[j][0]) * (matrix[k][0] - matrix[j][0]) + (matrix[k][1] - matrix[j][1]) * (matrix[k][1] - matrix[j][1]));
				AC = sqrt((matrix[k][0] - matrix[i][0]) * (matrix[k][0] - matrix[i][0]) + (matrix[k][1] - matrix[i][1]) * (matrix[k][1] - matrix[i][1]));
				cABC = (AB * AB + BC * BC - AC * AC) / (2 * AB * BC);
				cBCA = (AB * AB + AC * AC - BC * BC) / (2 * AB * AC);
				ABC = 180 * acos(cABC) / 3.14159265358979323846;
				BCA = 180 * acos(cBCA) / 3.14159265358979323846;
				CAB = 180 - ABC - BCA;
//				cout << ABC << " " << BCA << " " << CAB << endl;
				if (max(max(ABC,BCA),CAB) > anglemax)
				{
					anglemax = max(max(ABC, BCA), CAB);
					answer1 = i;
					answer2 = j;
					answer3 = k;
				}
//				cout << anglemax << endl;
			}
		}
	}



	if (anglemax > 90)
		cout << matrix[answer1][0] << " " << matrix[answer1][1] << endl << matrix[answer2][0] << " " << matrix[answer2][1] << endl << matrix[answer3][0] << " " << matrix[answer3][1];
	else
		cout << "Error";
}

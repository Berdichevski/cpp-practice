#include <iostream>

using namespace std;

int main()
{
    int arr[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i][j] != 0)
            {
                cout << "FALSE";
                return 0;
            }
        }
    }
    cout << "TRUE";
    return 0;
}
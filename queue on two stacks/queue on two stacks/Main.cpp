#include "Header.h"
#include <iostream>
using namespace std;


int main() 
{
    Queue queue;
    int len;
    cout << "Input length" << endl;
    cin >> len;
    int newVal;
    for (int i = 0; i < len; i++)
    {
        cout << "Input next node" << endl;
        cin >> newVal;
        queue.push(newVal);
    }

    for (int i = 0; i < len; i++)
    {
        cout << "Popped element: " << queue.pop() << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
using namespace std;

int main()
{
    BinaryTree tree;

    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "Unable to open file." << endl;
        return 1;
    }

    int n;
    file >> n;
    while (n)
    {
        int val;
        file >> val;
        tree.Add(val);
        n--;
    }

    tree.printTree(tree.getRoot());
    cout << endl;

    string result = tree.isBalanced(tree.getRoot()) ? "True" : "False";
    cout << result;
}
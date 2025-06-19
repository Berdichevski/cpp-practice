#include <iostream>
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

    BinaryTree symmetricTree(tree.createSymmetricTree(tree.getRoot()));

    symmetricTree.printTree(symmetricTree.getRoot());
    return 0;
}
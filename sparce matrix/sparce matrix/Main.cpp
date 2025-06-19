#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void main()
{
    ifstream fin("in1.txt");

    if (!fin.is_open())
    {
        cout << "Error!";
    }

    //считывание матрицы 1

    int rowNum, colNum;
    fin >> rowNum >> colNum;

    SparseMatrix matrix1 = SparseMatrix(rowNum, colNum);

    int curRow = 0;
    int curCol = 0;
    int tempVal;
    for (int k = 0; k < rowNum * colNum; k++)
    {
        fin >> tempVal;
        if (tempVal != 0)
        {
            matrix1.matrix->append(curRow, curCol, tempVal);
//            cout << curRow << " " << curCol << " " << tempVal << endl;
        }
        curCol++;
        if (curCol >= colNum)
        {
            curCol = 0;
            curRow++;
        }
    }

    //считывание матрицы 2

    fin >> rowNum >> colNum;

    SparseMatrix matrix2 = SparseMatrix(rowNum, colNum);

    curRow = 0;
    curCol = 0;
    for (int k = 0; k < rowNum * colNum; k++)
    {
        fin >> tempVal;
        if (tempVal != 0)
        {
            matrix2.matrix->append(curRow, curCol, tempVal);
//            cout << curRow << " " << curCol << " " << tempVal << endl;
        }
        curCol++;
        if (curCol >= colNum)
        {
            curCol = 0;
            curRow++;
        }
    }

    //считывание матрицы 3

    fin >> rowNum >> colNum;

    SparseMatrix matrix3 = SparseMatrix(rowNum, colNum);

    curRow = 0;
    curCol = 0;
    for (int k = 0; k < rowNum * colNum; k++)
    {
        fin >> tempVal;
        if (tempVal != 0)
        {
            matrix3.matrix->append(curRow, curCol, tempVal);
//            cout << curRow << " " << curCol << " " << tempVal << endl;
        }
        curCol++;
        if (curCol >= colNum)
        {
            curCol = 0;
            curRow++;
        }
    }

    //конец ввода

    cout << "Matrix1" << endl;
    matrix1.print();
    cout << endl << endl;
    cout << "Matrix2" << endl;
    matrix2.print();
    cout << endl << endl;
    cout << "Matrix3" << endl;
    matrix3.print();
    cout << endl << endl;

    cout << "Addition of 1 and 2" << endl;
    matrix1.add(matrix2).print();
    cout << endl << endl;

    cout << "Substraction of 2 from 1" << endl;
    matrix1.subtract(matrix2).print();
    cout << endl << endl;

    int scalar;
    cout << "Input scalar for multiplying" << endl;
    cin >> scalar;
    cout << "Multiplication of 1 and scalar" << endl;
    matrix1.multiply(scalar).print();
    cout << endl << endl;

    cout << "Multiplication of 1 and 3" << endl;
    matrix1.multiply(matrix3).print();
    cout << endl;

    fin.close();
}

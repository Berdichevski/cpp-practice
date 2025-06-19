#pragma once
#include <iostream>

struct element
{
    element(int row, int col, int value);
    int rowIndex;
    int colIndex;
    int value;
    element* next;
};

class elementList
{
private:
    element* head;
    element* tail;
public:
    element* getHead();
    void setHead(element* n);
    element* getTail();
    void setTail(element* n);
    elementList();
    void append(int row, int col, int value);
};

class SparseMatrix {
private:
    int rows;
    int cols;
public:
    elementList* matrix;
    SparseMatrix(int numRows, int numCols);
    SparseMatrix(const SparseMatrix& other);
    SparseMatrix add(const SparseMatrix& other);
    SparseMatrix subtract(const SparseMatrix& other);
    SparseMatrix multiply(int scalar);
    SparseMatrix multiply(const SparseMatrix& other);
    void print();
};

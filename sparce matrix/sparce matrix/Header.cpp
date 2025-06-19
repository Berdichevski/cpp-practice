#include "Header.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix(int numRows, int numCols)
{
    rows = numRows;
    cols = numCols;
    matrix = new elementList();
}

SparseMatrix::SparseMatrix(const SparseMatrix& other)  
{
    rows = other.rows;
    cols = other.cols;
    elementList* MatrixCopied = new elementList();
    element* n = other.matrix->getHead();
    while (n != nullptr)
    {
        MatrixCopied->append(n->rowIndex, n->colIndex, n->value);
        n = n->next;
    }

    matrix = new elementList();

    matrix->setHead(MatrixCopied->getHead());
    matrix->setTail(MatrixCopied->getTail());
}

SparseMatrix SparseMatrix::add(const SparseMatrix& other)
{
    if (rows != other.rows || cols != other.cols) 
    {
        cout << "Matrix dimensions do not match for addition." << endl;
        return *this;
    }

    SparseMatrix result(*this);
    
    element* n = other.matrix->getHead();
    while (n != nullptr)
    {
        bool flagSum = 0;
        element* m = result.matrix->getHead();
        while (m != nullptr)
        {
            if ((m->colIndex == n->colIndex) && (m->rowIndex == n->rowIndex))
            {
                m->value += n->value;
                flagSum = 1;
            }
            m = m->next;
        }
        if (!flagSum)
        {
            result.matrix->append(n->rowIndex, n->colIndex, n->value);
        }
        n = n->next;
    }
    return result;
}

SparseMatrix SparseMatrix::subtract(const SparseMatrix& other)
{
    if (rows != other.rows || cols != other.cols) 
    {
        cout << "Matrix dimensions do not match!" << endl;
        return *this;
    }

    SparseMatrix result(*this);

    element* n = other.matrix->getHead();
    while (n != nullptr)
    {
        bool flagSub = 0;
        element* m = result.matrix->getHead();
        while (m != nullptr)
        {
            if ((m->colIndex == n->colIndex) && (m->rowIndex == n->rowIndex))
            {
                m->value -= n->value;
                flagSub = 1;
            }
            m = m->next;
        }
        if (!flagSub)
        {
            result.matrix->append(n->rowIndex, n->colIndex, n->value * (-1));
        }
        n = n->next;
    }
    return result;
}

SparseMatrix SparseMatrix::multiply(int scalar)
{
    SparseMatrix result(*this);

    element* n = result.matrix->getHead();
    while (n != nullptr)
    {
        n->value *= scalar;
        n = n->next;
    }
    return result;
}

SparseMatrix SparseMatrix::multiply(const SparseMatrix& other)
{
    if (cols != other.rows)
    {
        cout << "Cannot multiply!" << endl;
        return *this;
    }

    SparseMatrix result(rows, other.cols);

    element* m = matrix->getHead();
    while (m != nullptr)
    {
        element* n = other.matrix->getHead();
        while (n != nullptr)
        {
            if (m->colIndex == n->rowIndex)
            {
                int newValue = m->value * n->value;
                element* existingElement = result.matrix->getHead();
                bool found = 0;
                while (existingElement != nullptr) 
                {
                    if (existingElement->rowIndex == m->rowIndex && existingElement->colIndex == n->colIndex) 
                    {
                        existingElement->value += newValue;
                        found = 1;
                        break;
                    }
                    existingElement = existingElement->next;
                }

                if (!found) 
                {
                    result.matrix->append(m->rowIndex, n->colIndex, newValue);  
                }
            }
            n = n->next;
        }
        m = m->next;
    }

    return result;
}

void SparseMatrix::print() 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool flagPrinted = 0;
            element* n = matrix->getHead();
            while (n != nullptr)
            {
                if ((n->colIndex == j) && (n->rowIndex == i))
                {
                    cout << n->value << " ";
                    flagPrinted = 1;
                }
                n = n->next;
            }
            if (!flagPrinted)
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

element::element(int row, int col, int value) :rowIndex(row), colIndex(col), value(value), next(nullptr) {}

elementList::elementList() :head(nullptr), tail(nullptr) {}

element* elementList::getHead()
{
    return head;
}

void elementList::setHead(element* n)
{
    head = n;
}

element* elementList::getTail()
{
    return tail;
}

void elementList::setTail(element* n)
{
    tail = n;
}

void elementList::append(int row, int col, int value)
{
    element* n = new element(row,col,value);
    if (head == nullptr)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
}




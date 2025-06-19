#include "Struct.h"
#include <fstream>
using namespace std;

matrix::matrix()
{
    this->n = 0;
    this->m = 0;
    this->data = nullptr;
}

matrix::matrix(const int& n,const int& m) 
{
	this->n = n;
	this->m = m;
    

	this->data = new double* [n];
	for (int i = 0; i < n; i++) 
	{
		this->data[i] = new double[m];
	}
}


matrix::~matrix()
{
    for (int i = 0; i < n; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

void matrix::readMatrix(ifstream& fin)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			fin >> data[i][j];
		}
	}
}

bool matrix::isSymetrical()
{
    if (n != m)
    {
        return false; 
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[i][j] != data[j][i])
            {
                return false; 
            }
        }
    }

    return true;
}

void matrix::writeMatrix(ofstream& fout)
{
    fout << this->n << ' ' << this->m << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fout << data[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
}



double matrix::trace()
{
    double traceSum = 0.0;

    for (int i = 0; i < n; i++)
    {
        traceSum += data[i][i];
    }

    return traceSum;
}





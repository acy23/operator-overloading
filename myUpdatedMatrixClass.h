#ifndef _myupdatedmatrixclass
#define _myupdatedmatrixclass
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <ostream>
#include <istream>
using namespace std;

class Matrix2D {
	private: 
		
		int rows, cols;
		int **data;

    public:
		
		Matrix2D(); //default constructor
		Matrix2D(const int &, const int &);
		int GetIndex(const int &, const int &) const;
		void SetIndex(const int &, const int &, const int &) const;
		bool isEmpty();
		
		Matrix2D operator +(const Matrix2D& m);
		Matrix2D operator+=(const Matrix2D& m);

		void operator =(const Matrix2D& m);

		friend istream& operator >> (istream& is, Matrix2D& m) {
			string s;
			while (is >> s)
			{
				for (int i = 0; i < m.rows; i++) {
					for (int j = 0; j < m.cols; j++)
					{
						m.data[i][j] = stoi(s);
					}
				}
				return is;
			}
			
		}
		friend ostream& operator << (ostream& os, Matrix2D& m) {
			for (int i = 0; i < m.rows; ++i) {
				for (int j = 0; j < m.cols; ++j) {
					os << m.data[i][j] << " ";
				}
				os << '\n';
			}
			return os;
		}
		
};

Matrix2D::Matrix2D()  //default constructor
{ 
	rows = 0;
	cols = 0;
	**data = NULL;
}


Matrix2D::~Matrix2D() //destructor
{
	
	for (int x = 0; x < rows; x++)
	{
		delete[] data[x];
	}
	delete[] data;
}


Matrix2D::Matrix2D(const Matrix2D& m) //copy constructor
{
	cols = m.cols;
	rows = m.rows;
	data = new int* [m.rows]();
	
	for (int i = 0; i < m.rows; i++)
	{
		data[i] = new int[m.cols];
		
	}
	for (int i = 0; i < m.rows; i++)
		for (int j = 0; j < m.cols; j++)
			data[i][j] = m.data[i][j];

}

Matrix2D::Matrix2D(const int & r, const int & c): rows(r), cols(c) {
	data = new int* [r]; 
	for (int i = 0; i<rows; i++) 
		data[i] = new int[cols];   
}

int Matrix2D::GetIndex(const int & i, const int & j) const{
    return data[i][j];
}

void Matrix2D::SetIndex(const int & i, const int & j, const int &value) const{
    data[i][j] = value;
}

bool Matrix2D::isEmpty() 
{
	
	if (data) {
		return true;
	}
	else {
		return false;
	}
}

//Operator overloading functions

Matrix2D Matrix2D::operator+(const Matrix2D& m)
{
	Matrix2D temp(rows, cols);
	if (rows != m.rows || cols != m.cols)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				temp.data[i][j] = data[i][j];
		return temp;
	}
	else
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				temp.data[i][j] += m.data[i][j] + data[i][j];
	}
	return temp;
}
Matrix2D Matrix2D::operator += (const Matrix2D& m)
{
	Matrix2D temp(rows, cols);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			data[i][j] += m.data[i][j];
		}
	}
	return temp;
}

void Matrix2D::operator=(const Matrix2D& m)
{
	if (data != m.data && cols == m.cols && rows == m.rows)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				data[i][j] = m.data[i][j];
	}
}

#endif

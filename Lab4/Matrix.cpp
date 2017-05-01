#include "Matrix.h"
using namespace std;

// Definition of class Matrix


Matrix  Matrix:: transpose(){				// Transpose function member function of class Matrix
	int nrow=cols,ncol=rows;
	Matrix mat(nrow,ncol);
	int **Array = new int *[nrow];
	for(int i=0;i<nrow;i++)
		Array[i] = new int [ncol];
	for(int i=0;i<nrow;i++)
		for(int j=0;j<ncol;j++)
			Array[i][j] = matrix[j][i];
	mat.inputMatrix(Array);
	return mat;
}

void Matrix:: inputMatrix(int **array){			// inputMatrix function for taking an array as input for Matrix object  : Member of class Matrix
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] = array[i][j];
}

void Matrix:: inputMatrix(){				// Overloaded function of inputMatrix function, Takes input from stdin for Matrix object  : Member of class Matrix
	cout<<"Enter "<<rows<<"*"<<cols<<" numbers: "<<endl;
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			cin>>matrix[i][j];
}

Matrix Matrix:: operator+( Matrix M){			// Overloaded '+' operator for two matrix objects  : Member of class Matrix
	Matrix mat(rows,cols);
	int **Array = new int *[rows];
	for(int i=0;i<rows;i++)
		Array[i] = new int [cols];
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			Array[i][j] = matrix[i][j]+M.getElement(i,j);
	mat.inputMatrix(Array);
	return mat;
}

Matrix Matrix:: operator-( Matrix M){			// Overloaded '-' operator for two Matrix objects  : Member of class Matrix
	Matrix mat(rows,cols);
	int **Array = new int *[rows];
	for(int i=0;i<rows;i++)
		Array[i] = new int [cols];
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			Array[i][j] = matrix[i][j]-M.getElement(i,j);
	mat.inputMatrix(Array);
	return mat;
}

Matrix operator*(int scale, Matrix M){			// Overloaded '*' operator for Scalor and Matrix object   : Friend of class Matrix
	Matrix mat(M.rows,M.cols);
	int **Array = new int *[M.rows];
	for(int i=0;i<M.rows;i++)
		Array[i] = new int [M.cols];
	for(int i=0;i<M.rows;i++)
		for(int j=0;j<M.cols;j++)
			Array[i][j] = scale*M.matrix[i][j];
	mat.inputMatrix(Array);
	return mat;
}

Matrix operator*(Matrix M,int scale){			// Overloaded '*' operator for Matrix object and a Scalor  : friend of class Matrix
	Matrix mat(M.rows,M.cols);
	int **Array = new int *[M.rows];
	for(int i=0;i<M.rows;i++)
		Array[i] = new int [M.cols];
	for(int i=0;i<M.rows;i++)
		for(int j=0;j<M.cols;j++)
			Array[i][j] = scale*M.matrix[i][j];
	mat.inputMatrix(Array);
	return mat;
}

Matrix Matrix:: operator*( Matrix M){			// Overloaded '*' operator for two Matrix objects  : Member of class Matrix
	Matrix mat(rows,M.getCols());
	int **Array = new int *[rows];
	int col = M.getCols();
	for(int i=0;i<rows;i++)
		Array[i] = new int [col];
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			Array[i][j] = 0;
			for(int k=0;k<cols;k++)
				Array[i][j] = Array[i][j]+matrix[i][k]*(M.getElement(k,j));
		}
	}
	mat.inputMatrix(Array);
	return mat;
}

Matrix Matrix:: operator= ( Matrix rhs){			// Overloaded '=' operator for two Matrix objects  : Member of class Matrix
	this->rows = rhs.getRows();
	this->cols = rhs.getCols();
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			matrix[i][j] = rhs.getElement(i,j);
	return *this;
}

Matrix:: Matrix(const int row,const int col){			// Constructor for Matrix
	rows = row;
	cols = col;
	matrix = new int *[row];
	for(int i=0;i<row;i++)
		matrix[i] = new int [col];
	for(int i=0;i<rows;i++)
		for(int j=0;j<col;j++) matrix[i][j]=0;
}

void Matrix:: showMatrix(void){					// showMatrix function to show Matrix
	for(int i=0;i<rows;i++){
		cout<<endl<<"\t";
		for(int j=0;j<cols;j++) 
			cout<<matrix[i][j]<<"  ";
	}
	cout<<endl;
}


// class Matrix prototype

class Matrix{
	int rows;
	int cols;
	int **matrix;
	public:
		int getRows(){return rows;}
		int getCols(){return cols;}
		int getElement(int r,int c){return matrix[r][c];}
		Matrix(int row,int col);
		void showMatrix();
		void inputMatrix(void);
		void inputMatrix(int **);
		Matrix operator= (Matrix );
		Matrix operator+(Matrix );
		Matrix operator-(Matrix );
		Matrix operator*( Matrix );
		friend Matrix operator*(int, Matrix);
		friend Matrix operator*( Matrix,int);
		Matrix transpose();
};

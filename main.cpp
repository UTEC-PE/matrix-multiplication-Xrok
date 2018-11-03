#include <iostream>
using namespace std;

void inicarMatrix(int** &matrix, int x, int y){
	matrix = new int*[x];
	for (int i = 0; i < x; ++i)
	{
		matrix[i]= new int[y];
	}
};

void llenarMatrix(int** &m, int x,int y){
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			m[i][j]=1;
		}
	}
};

void printMatrix(int** m,int x, int y){
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			cout<<m[i][j];
		}
		cout<<endl;
	}
};

int* mulltiplicar(int*m1,int**m2,int x1, int y1,int y2) {
	
	int result[y1];

	for (int k = 0; k < y1; ++k)
	{
		int temp=0;
		
		for (int i = 0; i < y1; ++i)
		{
			temp += m1[i] * m2[i][k];
		}

		result[k]=temp;
	}
	return result;
};



int main()
{
	int **matrix1, **matrix2, *test;
	int x=3,y=3;
	int result[y];
	inicarMatrix(matrix1,x,y);
	llenarMatrix(matrix1,x,y);
	printMatrix(matrix1,x,y);
	inicarMatrix(matrix2,x,y);
	llenarMatrix(matrix2,x,y);
	//test=matrix1[1];

	//cout<<test[1];

	test = mulltiplicar(matrix1[1],matrix2,x,y,y);

	for (int i = 0; i < y; ++i)
	{
		cout<<result[i]<<" ";
	}



	return 0;
}
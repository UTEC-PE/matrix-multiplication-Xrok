#include <iostream>
#include <thread>

using namespace std;

void inicarMatrix(int** &matrix, int x, int y){
	matrix = new int*[x];
	for (int i = 0; i < x; ++i)
	{
		matrix[i]= new int[y];
	}
}

void llenarMatrix(int** &m, int x,int y){
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			m[i][j]=1;
		}
	}
}

void printMatrix(int** m,int x, int y){
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			cout<<m[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

void mulltiplicar(int*m1,int**m2,int x1, int y1,int y2,int** &result,int row) {
	

	for (int k = 0; k < y1; ++k)
	{
		int temp=0;
		
		for (int i = 0; i < y1; ++i)
		{
			temp += m1[i] * m2[i][k];
		}
		result[k][row]=temp;
	}

};



int main()
{
	int x=3,y=3;
	int **matrix1, **matrix2, **result ;

	thread threads[y];
	inicarMatrix(result,x,y);
	llenarMatrix(result,x,y);

	inicarMatrix(matrix1,x,y);
	llenarMatrix(matrix1,x,y);
	printMatrix(matrix1,x,y);

	inicarMatrix(matrix2,x,y);
	llenarMatrix(matrix2,x,y);
	printMatrix(matrix2,x,y);


	for (int i = 0; i < y; ++i)
	{
		threads[i] = thread (mulltiplicar,matrix1[i],matrix2,x,y,y,result,i);
	}
	for (int i = 0; i < y; ++i) {
        threads[i].join();
    }

	printMatrix(result,x,y);



	return 0;
}
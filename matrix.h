#ifndef matrix_h
#define matrix_h
#include<iostream>
#include<stdlib.h>

using namespace std;
class Matrix
{
		int 	**data;
		int 	r,c;
	public :
		int 	input();
		int 	display();
		Matrix 	add(Matrix b);
		Matrix  sub(Matrix b);
		Matrix  mul(Matrix b);
		Matrix  transpose();
		Matrix();
		Matrix(int row,int column);
		~Matrix();
};
#endif	

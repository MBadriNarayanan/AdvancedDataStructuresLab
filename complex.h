#ifndef complex_h
#define complex_h
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class Complex
{
		int 	real;
		int 	imaginary;
		char 	sg;
	public  : 
		Complex();
		Complex(int r,int i);
		int input();
		int display();
		Complex operator + (Complex b);
		Complex operator - (Complex b);
		Complex operator * (Complex b);
};	
#endif


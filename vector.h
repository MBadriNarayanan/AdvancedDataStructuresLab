#ifndef vector_h
#define vector_h
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
class Vector
{
			int 	*data;
			int 	dimensions;
	
	public :
			int input();
			int display();
			Vector add(Vector b);
			Vector sub(Vector b);
			int    dotproduct(Vector b);
			Vector();
			Vector(int n);
};
#endif

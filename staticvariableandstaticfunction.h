#ifndef staticvariableandstaticfunction_h
#define staticvariableandstaticfunction_h
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Shapes
{
	static float 	length;
	static float 	breadth;
	static float 	height;
	static float	radius;
	static int 		choice;

	public :

		static int count;
		Shapes();
		static int input();
		static int display();
		static float volume();
		static float tsa();
		static float csa();
};
#endif
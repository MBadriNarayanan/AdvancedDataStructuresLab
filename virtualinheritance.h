#ifndef virtualinheritance_h
#define virtualinheritance_h

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Circle
{
	public :
	float	radius;
	int 	getcircle();
	float   area();
	float   circumference();
	int 	display();
	virtual float volume() = 0;
	virtual float tsa() = 0;
	virtual float csa() = 0;
	Circle();
};

class Cylinder : public Circle
{
	public : 
	float height;
	int   getheight();
	float volume();
	float tsa();
	float csa();
	int cylinderdisplay();
	Cylinder();
};

class Cone : public Cylinder
{
	public : 
	float length;
	float volume();
	float tsa();
	float csa();
	int   getlength();
	int   conedisplay();
	Cone();
};
#endif
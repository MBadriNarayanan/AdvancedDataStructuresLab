#include"virtualinheritance.h"

Circle :: Circle()
{

}

Cylinder :: Cylinder()
{

}

Cone :: Cone()
{

}

int Circle :: getcircle()
{
	cout<<"\n\n Enter Radius : ";
	cin>>radius;
	cout<<"\n\n";
	if(radius>=0)return 1;
	else return 0;
}

float Circle :: area()
{
	return 3.14 * radius * radius ;
}

float Circle :: circumference()
{
	return 2 * 3.14 * radius;
}
int Circle :: display()
{
	cout<<" Radius : "<<radius<<"\n\n";
	return 1;
}
int Cylinder :: getheight()
{
	Circle :: getcircle();
	cout<<"\n\n Enter Height : ";
	cin>>height;
	cout<<"\n\n";
	if(height>=0)return 1;
	else return 0;
}
float Cylinder :: tsa()
{
	return 2 * 3.14 * radius * (height + radius);
}

float Cylinder :: csa()
{
	return 2 * 3.14 * radius * height;
}

float Cylinder :: volume()
{
	return 3.14 * radius * radius * height ;
}

int Cylinder :: cylinderdisplay()
{
	Circle :: display();
	cout<<" Height : "<<height<<"\n\n";
	return 1;
}
int Cone :: getlength()
{
	float sum;
	Cylinder :: getheight();
	sum = (radius * radius ) + (height * height );
	length = sqrt(sum);
}

int Cone :: conedisplay()
{
	Cylinder :: cylinderdisplay();
	cout<<" Length : "<<length<<"\n\n";
	return 1;
}
float Cone :: tsa()
{
	return 3.14 * radius * (length + radius);

}

float Cone :: csa()
{
	return 3.14 * radius * length;
}

float Cone :: volume()
{
	return (1/3.0) * 3.14 * radius * radius * height;
}
#include"complex.h"
Complex :: Complex()
{
	real = 10;
	imaginary = 10 ;
	if(imaginary>=0)sg='+';
	else sg='-';
}

Complex :: Complex(int r,int i)
{
	real = r;
	imaginary = i;
	if(imaginary>=0)sg='+';
	else sg='-';
}
int Complex :: input()
{
	cout<<"\n\n Input \n\n";
	cout<<" Enter Real Part : ";
	cin>>real;
	cout<<" Enter Imaginary Part : ";
	cin>>imaginary;
	if(imaginary>=0)sg='+';
	else sg='-';
	cout<<"\n\n";
	return 1;
}
int Complex :: display()
{
	cout<<"\n\n Display \n\n";
	cout<<" Complex Number : "<<real<<" "<<sg<<" "<<abs(imaginary)<<"i\n\n";
	return 1;
	
}
Complex Complex :: operator + (Complex b)
{
	Complex c;
	c.real = real + b.real ;
	c.imaginary = imaginary + b.imaginary ;
	if(c.imaginary>=0)c.sg='+';
	else c.sg='-';
	return c;
}
Complex Complex :: operator - (Complex b)
{
	Complex c;
	c.real = real - b.real ;
	c.imaginary = imaginary - b.imaginary ;
	if(c.imaginary>=0)c.sg='+';
	else c.sg='-';
	return c;
}
Complex Complex :: operator * (Complex b)
{
	Complex c;
	c.real = (real * b.real) - (imaginary * b.imaginary) ;
	c.imaginary = (real * b.imaginary) + (b.real * imaginary) ;
	if(c.imaginary>=0)c.sg='+';
	else c.sg='-';
	return c;
}

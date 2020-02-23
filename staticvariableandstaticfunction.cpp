#include"staticvariableandstaticfunction.h"
float Shapes ::	length = 0;
float Shapes :: breadth = 0;
float Shapes ::	height = 0;
float Shapes ::	radius = 0;
int Shapes :: choice = 0;
int Shapes :: count = 0;
Shapes :: Shapes()
{
	length = 0;
	breadth = 0;
	height = 0;
	radius = 0;
	choice = 100;
}
int Shapes :: input()
{
	cout<<"\n\n Input \n\n";
	cout<<" Enter Choice : ";
	cin>>choice;
	count ++ ;
	switch(choice)
	{
		case 1 :
				{
						cout<<"\n\n Cube \n\n";
						cout<<" Enter Length : ";
						cin>>length;
						breadth = length;
						height = length;
						radius = 0;
						break;
				}
		case 2 :
				{
						cout<<"\n\n Cuboid \n\n";
						cout<<" Enter Length : ";
						cin>>length;
						cout<<" Enter Breadth : ";
						cin>>breadth;
						cout<<" Enter Height : ";
						cin>>height;
						break;
				}
		case 3 :
				{
						cout<<"\n\n Sphere \n\n";
						cout<<" Enter Radius : ";
						cin>>radius;
						length = breadth = height = 0;
						break;
				}
		case 4 :
				{
						cout<<"\n\n Cylinder \n\n";
						cout<<" Enter Radius : ";
						cin>>radius;
						cout<<" Enter Height : ";
						cin>>height;
						length = breadth = 0;
						break;
				}
		case 5 :
				{
					float sum;
						sum = 0;
						cout<<"\n\n Cone \n\n";
						cout<<" Enter Radius : ";
						cin>>radius;
						cout<<" Enter Height : ";
						cin>>height;
						sum = (radius * radius) + (height * height);
						length = sqrt(sum);
						breadth = 0;
						break;
				}
		default :
				{
						cout<<"\n\n Default \n\n";
						length = 0;
						breadth = 0;
						radius = 0;
						height = 0;
						break;
				}
	}
	cout<<"\n\n";
	return 1;
}
int Shapes :: display()
{
	cout<<"\n\n Display \n\n";
	cout<<" Choice : "<<choice<<"\n\n";
	switch(choice)
	{
		case 1 :
				{
						cout<<"\n\n Cube \n\n";
						cout<<" Length : "<<length<<"\n";
						cout<<" Breadth : "<<breadth<<"\n";
						cout<<" Height : "<<height<<"\n";
						cout<<" Radius : "<<radius<<"\n\n";
						break;
				}
		case 2 :
				{
						cout<<"\n\n Cuboid \n\n";
						cout<<" Length : "<<length<<"\n";
						cout<<" Breadth : "<<breadth<<"\n";
						cout<<" Height : "<<height<<"\n";
						cout<<" Radius : "<<radius<<"\n\n";
						break;
				}
		case 3 :
				{
						cout<<"\n\n Sphere \n\n";
						cout<<" Length : "<<length<<"\n";
						cout<<" Breadth : "<<breadth<<"\n";
						cout<<" Height : "<<height<<"\n";
						cout<<" Radius : "<<radius<<"\n\n";
						break;
				}
		case 4 :
				{
						cout<<"\n\n Cylinder \n\n";
						cout<<" Length : "<<length<<"\n";
						cout<<" Breadth : "<<breadth<<"\n";
						cout<<" Height : "<<height<<"\n";
						cout<<" Radius : "<<radius<<"\n\n";
						break;
				}
		case 5 :
				{
						cout<<"\n\n Cone \n\n";
						cout<<" Length : "<<length<<"\n";
						cout<<" Breadth : "<<breadth<<"\n";
						cout<<" Height : "<<height<<"\n";
						cout<<" Radius : "<<radius<<"\n\n";
						break;
				}
		default :
				{
						cout<<" Default \n\n";
						cout<<" Length : "<<length<<"\n";
						cout<<" Breadth : "<<breadth<<"\n";
						cout<<" Height : "<<height<<"\n";
						cout<<" Radius : "<<radius<<"\n\n";
						break;
				}
	}
	return 1;
}
float Shapes :: volume()
{
	switch(choice)
	{
		case 1 :
				{
					return length * length * length;
					break;
				}
		case 2 :
				{
					return length * breadth * height;
					break;
				}
		case 3 :
				{
					return (4/3) * 3.14 * radius * radius * radius ;
					break;
				}
		case 4 :
				{
					return 3.14 * radius * radius * height ;
					break;
				}
		case 5 :
				{
					return 3.14 * (1/3) * radius * radius * height ;
					break;
				}
		default :
				{
					return 0 ;
					break;
				}
	}
}
float Shapes :: tsa()
{
	switch(choice)
	{
		case 1 :
				{
					return 6 * length * length;
					break;
				}
		case 2 :
				{
					return 2 * ((length * breadth) + (breadth * height) +(length * height));
					break;
				}
		case 3 :
				{
					return 4 * 3.14 * radius * radius ;
					break;
				}
		case 4 :
				{
					return 3.14 * radius * radius * height ;
					break;
				}
		case 5 :
				{
					return 3.14 * (1/3) * radius * radius * height ;
					break;
				}

		default :
				{
					return 0 ;
					break;
				}
	}
}
float Shapes :: csa()
{
	switch(choice)
	{
		case 1 :
				{
					return 4 * length * length;
					break;
				}
		case 2 :
				{
					return 2 * (length + breadth) * height;
					break;
				}
		case 3 :
				{
					return 4 * 3.14 * radius * radius ;
					break;
				}
		case 4 :
				{
					return 2 * 3.14 * radius *(radius + height) ;
					break;
				}
		case 5 :
				{
					return 3.14 * radius * (radius + length) ;
					break;
				}
		default :
				{
					return 0 ;
					break;
				}
	}
}
#include"virtualinheritance.h"

int main()
{

	int choice;
	do
	{
			cout<<"\n\n\n Virtual Inheritance \n\n\n";
			cout<<" 1. Circle \n";
			cout<<" 2. Cylinder \n";
			cout<<" 3. Cone \n";
			cout<<" Enter Choice : ";
			cin>>choice;
			switch(choice)
			{
				case 1 :
						{
							Cylinder c;
							c.getcircle();
							c.display();
							cout<<" Area Is : "<<c.area()<<"\n\n";
							cout<<" Circumference Is : "<<c.circumference()<<"\n\n";
							break;
						}

				case 2 :
						{
							Cylinder c;
							c.getheight();
							c.cylinderdisplay();
							cout<<" TSA Is : "<<c.tsa()<<"\n\n";
							cout<<" CSA Is : "<<c.csa()<<"\n\n";
							cout<<" Volume Is : "<<c.volume()<<"\n\n";
							break;
						}

				case 3 :
						{
							Cone c;
							c.getlength();
							c.conedisplay();
							cout<<" TSA Is : "<<c.tsa()<<"\n\n";
							cout<<" CSA Is : "<<c.csa()<<"\n\n";
							cout<<" Volume Is : "<<c.volume()<<"\n\n";
							break;
						}
				default :
						{

							cout<<"\n\n Default \n\n";
							break;
						}
			}
			cout<<" Do You Want To Continue (Type 0 Or 1) : ";
			cin>>choice;
	}while(choice);


	cout<<"\n\n\n The End \n\n\n";
	return 0;
}
#include"staticvariableandstaticfunction.h"

int main()
{
	int    option;
	Shapes a;
		do
		{
			cout<<"\n\n\n Static Variables And Static Function \n\n";
			cout<<" 1. Cube \n";
			cout<<" 2. Cuboid \n";
			cout<<" 3. Sphere \n";
			cout<<" 4. Cylinder \n";
			cout<<" 5. Cone \n";
			a.input();
			a.display();
			cout<<" The Total Surface Area Is : "<<a.tsa()<<"\n\n";
			cout<<" The Curved Surface Area Is : "<<a.csa()<<"\n\n";
			cout<<" The Volume Is : "<<a.volume()<<"\n\n";
			cout<<" Do You Want To Continue (Type 0 Or 1) : ";
			cin>>option;
			if(option == 0)
			{
				cout<<"\n\n Number Of Shapes : "<<a.count<<"\n\n";
			}
		}while(option);
		cout<<"\n\n\n The End \n\n\n";
		return 0;
}
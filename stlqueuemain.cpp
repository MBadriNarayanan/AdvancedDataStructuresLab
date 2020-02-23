#include"stlqueue.h"
int main()
{
	Library a;
	int 	bookno1,temp;
			cout<<"\n\n\n Standard Template Library Using Queue On User Defined Class \n\n\n";
			cout<<" 1. Input \n";
			cout<<" 2. Display \n";
			cout<<" 3. Insert \n";
			cout<<" 4. Delete \n";
			
			cout<<"\n\n Input and Display \n\n";
			a.input();
			a.display();

			cout<<"\n\n Insert \n\n";
			a.insert();
			a.display();

			cout<<"\n\n Delete \n\n";
			a.delete1();
			a.display();

			cout<<"\n\n The End \n\n";
			return 0;		
}
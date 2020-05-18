#include"display_tree.h"


int main()
{
	cout<<"\n\n\n Red Black Tree \n\n\n";
	int data;
	int choice;
	RBT<int> b;
	cout<<"\n\n Creating The Red Tree \n\n";
	do
	{
		cout<<" Enter Data To Be Inserted : ";
		cin>>data;
		b.insert(data);
		cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	display_bst(b.getRoot());
	b.display();	
	cout<<"\n\n\n The End \n\n\n";
	return 0;
}

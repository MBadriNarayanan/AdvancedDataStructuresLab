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
	cout<<"\n\n\n";
	/*do
	{
		cout<<" Enter Data To Be Searched : ";
		cin>>data;
		b.search(data);
		cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	display_bst(b.getRoot());
	b.display();
	cout<<"\n\n\n";
	do
	{
		cout<<" Enter Data To Be Deleted : ";
		cin>>data;
		b.delete_key(data);
		cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	cout<<" Displaying The Deleted Tree \n\n";
	display_bst(b.getRoot());*/			
	cout<<"\n\n\n The End \n\n\n";
	return 0;
}
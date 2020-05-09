#include"display_tree.h"


int main()
{
	cout<<"\n\n\n Splay Tree \n\n\n";
	int data;
	int choice;
	Splay<int> b;
	cout<<"\n\n Creating The Splay Tree \n\n";
	do
	{
		cout<<" Enter Data To Be Inserted : ";
		cin>>data;
		b.insert(data);
		cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	cout<<"\n\n Final Splay Tree \n\n";
	display_bst(b.getRoot());
	cout<<"\n\n\n";
	do
	{
		cout<<" Enter Data To Be Searched : ";
		cin>>data;
		b.search(data);
		cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	cout<<"\n\n Final Splay Tree \n\n";
	display_bst(b.getRoot());
	cout<<"\n\n\n";
	do
	{
		cout<<" Enter Data To Be Deleted : ";
		cin>>data;
		b.delete_key(data);
		cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);	
	cout<<"\n\n Final Splay Tree \n\n";
	display_bst(b.getRoot());	
	cout<<"\n\n\n The End \n\n\n";
	return 0;
}
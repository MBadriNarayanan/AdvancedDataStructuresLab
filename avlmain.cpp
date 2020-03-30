#include"display_tree.h"


int main()
{
	cout<<"\n\n\n AVLTree \n\n\n";
	int data;
	int choice;
	AVL<int> b;
	cout<<"\n\n Creating The AVLTree \n\n";
	do
	{
		cout<<" Enter Data To Be Inserted : ";
		cin>>data;
		b.insert(data);
		cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	display_bst(b.getRoot());
	cout<<"\n\n\n";
	do
	{
		cout<<" Enter Data To Be Deleted : ";
		cin>>data;
		b.deleteNode(data);
		cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	display_bst(b.getRoot());					
	cout<<"\n\n\n The End \n\n\n";
	return 0;
}
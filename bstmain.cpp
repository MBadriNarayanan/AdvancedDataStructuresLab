#include"bst.h"
#include"bst1.h"

int main()
{
	cout<<"\n\n\n BinarySearchTree \n\n\n";
	int choice;
		cout<<" 1. Integer BST \n";
		cout<<" 2. Character BST \n";
		cout<<" 3. Float BST \n";
		cout<<" Enter Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : 
					{
						cout<<"\n\n Creating The BST \n\n";
						int data;
						BST<int> b;
						do
						{
							cout<<" Enter Data To Be Inserted : ";
							cin>>data;
							b.insert(data);
							cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
							cin>>choice;
						}while(choice);
						b.display();
						cout<<"\n\n\n";
						do
						{
							cout<<" Enter Data To Be Deleted : ";
							cin>>data;
							b.deleteNode(data);
							cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
							cin>>choice;
						}while(choice);
						b.display();
						cout<<"\n\n\n";
						break;
					}

			case 2 : 
					{
						cout<<"\n\n Creating The BST \n\n";
						char data;
						BST<char> b;
						do
						{
							cout<<" Enter Data To Be Inserted : ";
							cin>>data;
							b.insert(data);
							cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
							cin>>choice;
						}while(choice);
						b.display();
						cout<<"\n\n\n";
						do
						{
							cout<<" Enter Data To Be Deleted : ";
							cin>>data;
							b.deleteNode(data);
							cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
							cin>>choice;
						}while(choice);
						b.display();
						cout<<"\n\n\n";
						break;
					}

			case 3 : 
					{
						cout<<"\n\n Creating The BST \n\n";
						float data;
						BST<float> b;
						do
						{
							cout<<" Enter Data To Be Inserted : ";
							cin>>data;
							b.insert(data);
							cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
							cin>>choice;
						}while(choice);
						b.display();
						cout<<"\n\n\n";
						do
						{
							cout<<" Enter Data To Be Deleted : ";
							cin>>data;
							b.deleteNode(data);
							cout<<" Do You Have Any More Data To Be Deleted (Type 0 Or 1) : ";
							cin>>choice;
						}while(choice);
						b.display();
						cout<<"\n\n\n";
						break;
					}
			default :
					{
						cout<<"\n\n Default \n\n";
						break;
					}
		}
	cout<<"\n\n The End \n\n";
	return 0;
}
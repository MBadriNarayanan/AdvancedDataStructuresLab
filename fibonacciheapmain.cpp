#include"fibonacciheap.h"

int main()
{
	cout<<"\n\n\n Fibonacci Heap \n\n\n";
	int data;
	int choice;
	fib_heap<int> f;
	cout<<"\n\n Creating The Fibonacci Heap \n\n";
	do
	{
		cout<<" Enter Data To Be Inserted : ";
		cin>>data;
		f.insert(data);
		cout<<" Do You Have Any More Data (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	cout<<"\n\n Final Fibonacci Heap \n\n";
	f.display();
	cout<<"\n\n\n";
	do
	{
		cout<<" Extract Min ";
		cout<<" Minimum Data : "<<f.extract_min()<<"\n\n";
		cout<<" Do You Want To Continue (Type 0 Or 1) : ";
		cin>>choice;
	}while(choice);
	cout<<"\n\n Final Fibonacci Heap \n\n";
	f.display();
	cout<<"\n\n\n The End \n\n\n";
	return 0;
}
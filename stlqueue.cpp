#include"stlqueue.h"
ostream& operator <<(ostream& out,BookDetails a)
{
        cout<<" Book Number : ";
        out<<a.bookno<<endl;
		cout<<" Book Name : ";
		out<<a.name<<endl;
		cout<<" Author Name : ";
		out<<a.author<<endl;
		cout<<" Publisher Name : ";
		out<<a.publisher<<endl;
		cout<<" Publisher Number : ";
		out<<a.publishernumber<<endl;
		cout<<" Price : ";
		out<<a.price;
        	cout<<endl<<endl;
		return out;
}
istream& operator >>(istream& in,BookDetails& a)
{
        cout<<" Enter Book Number : ";
        in>>a.bookno;
		cout<<" Enter Book Name : ";
		in>>a.name;
		cout<<" Enter Author Name : ";
		in>>a.author;
		cout<<" Enter Publisher Name : ";
		in>>a.publisher;
		cout<<" Enter Publisher Number : ";
		in>>a.publishernumber;
		cout<<" Enter Price : ";
		in>>a.price;
		cout<<endl;
		return in;
}
int Library::input()
{
	cout<<"\n\n Input The Book Details \n\n";
	cout<<" Enter Maximum Number Of Books : ";
	cin>>maxsize;
	cout<<" Enter Number Of Books : ";
	cin>>size;
	if(size>maxsize)
	{
		cout<<"\n\n Size Greater Than Max Size \n\n";
		return 0;
	}
	else
	{
		BookDetails a;
		cout<<"\n\n";
		for(int i=0;i<size;i++)
		{
		     cin>>a;
		     data.push(a);
		     
		}
		return 1;
	}
}
int Library :: display()
{
        cout<<"\n\n Displaying The Books \n\n";
        if(data.empty())
        {
        	cout<<"\n\n Empty Queue \n\n";
        	return 0;
        }
        else
        {
			queue<BookDetails> Q;
			Q = data;
			while(!Q.empty())
			{
		     	cout<<Q.front();
		     	Q.pop();
			}
			return 1;
		}
}
Library::Library()
{
	size = 0;
	maxsize = size;
	BookDetails a;
	for(int i=0;i<size;i++)
	{
		a.bookno=0;
		a.name = "\0";
		a.author = "\0";
		a.publishernumber = 0;
		a.price = 0;
		a.publisher = "\0";
		data.push(a);
	}
}
Library :: Library(int n)
{
	maxsize = n;
	size = 0;
	BookDetails a;
	for(int i=0;i<size;i++)
	{
		a.bookno=0;
		a.name = "\0";
		a.author = "\0";
		a.publishernumber=0;
		a.price=0;
		a.publisher = "\0";
		data.push(a);
	}
}   
int Library ::insert()
{
		if(data.size()> maxsize)
		{
			cout<<"\n\n Book Cannot Be Inserted "<<endl;
			return -1;
		}
		else
		{
			BookDetails b;
			cout<<"\n\n Enter Details Of Book To Be Inserted \n\n";
			cin>>b;
			data.push(b);
			cout<<"\n\n Book Inserted \n\n";
			return 1;
		}
}
int Library ::delete1()
{
		if(data.size() == 0)
		{
			cout<<"\n\n Queue Is Empty \n\n";
			cout<<"\n\n Book Cannot Be Deleted \n\n";
			return -1;
		}
		else
		{
			data.pop();
			cout<<"\n\n Book Deleted \n\n";
			return 1;
		}
}

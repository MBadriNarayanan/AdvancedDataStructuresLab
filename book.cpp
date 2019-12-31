#include"book.h"
int Book::input()
{
	cout<<"\n\n Input The Book Details \n\n";
	cout<<" Enter Number Of Books : ";
	cin>>size;
	cout<<"\n\n";
	for(int i=0;i<size;i++)
	{
		cout<<" Enter Book Number : ";
		cin>>data[i].bookno;
		cout<<" Enter Book Name : ";
		cin>>data[i].name;
		cout<<" Enter Author Name : ";
		cin>>data[i].author;
		cout<<" Enter Publisher Name : ";
		cin>>data[i].publisher;
		cout<<" Enter Publisher Number : ";
		cin>>data[i].publishernumber;
		cout<<" Enter Price : ";
		cin>>data[i].price;
		cout<<endl;
	}
	return 1;
}
int Book ::singleinput()
{
		size=1;
		data=new BookDetails[size];
		cout<<" Enter Book Number : ";
		cin>>data[size-1].bookno;
		cout<<" Enter Book Name : ";
		cin>>data[size-1].name;
		cout<<" Enter Author Name : ";
		cin>>data[size-1].author;
		cout<<" Enter Publisher Name : ";
		cin>>data[size-1].publisher;
		cout<<" Enter Publisher Number : ";
		cin>>data[size-1].publishernumber;
		cout<<" Enter Price : ";
		cin>>data[size-1].price;
		cout<<endl;
		return 1;
}
int Book ::display()
{
	cout<<"\n\n Displaying The Books \n\n";
	for(int i=0;i<size;i++)
	{
		cout<<" Book Number : ";
		cout<<data[i].bookno<<endl;
		cout<<" Book Name : ";
		cout<<data[i].name<<endl;
		cout<<" Author Name : ";
		cout<<data[i].author<<endl;
		cout<<" Publisher Name : ";
		cout<<data[i].publisher<<endl;
		cout<<" Publisher Number : ";
		cout<<data[i].publishernumber<<endl;
		cout<<" Price : ";
		cout<<data[i].price;
		cout<<endl<<endl;
	}
		return 1;
}
Book::Book()
{
	size=15;
	data=new BookDetails[size];
	for(int i=0;i<size;i++)
	{
		data[i].bookno=0;
		data[i].name[0]='\0';
		data[i].author[0]='\0';
		data[i].publishernumber=0;
		data[i].price=0;
		data[i].publisher[0]='\0';
	}
}
Book :: Book(int n)
{
	size=n;
	data=new BookDetails[size];
	for(int i=0;i<size;i++)
	{
		data[i].bookno=0;
		data[i].name[0]='\0';
		data[i].author[0]='\0';
		data[i].publishernumber=0;
		data[i].price=0;
		data[i].publisher[0]='\0';
	}
}
int Book::sort()
{
	int 	n,i,j;
	Book 	temp;
	n=size;
	for(i=1;i<n;i++)
	{
		BookDetails t=data[i];
			for(j=i-1;((j>=0)&&(t.bookno<data[j].bookno));j--)
			{
				data[j+1]=data[j];
			}
			data[j+1]=t;
	}
	cout<<"\n\n Sorted In Ascending Order \n\n";
	return 1;
}
int Book ::search(int bookno1)
{
	int 	flag;
			flag=-1;
			for(int i=0;((i<size)&&(flag==-1));i++)
			{
				if(data[i].bookno==bookno1)flag=i+1;
			}
			if(flag==-1)
			{
				cout<<"\n\n Data Not Found \n\n";
				return -1;
			}
			else
			{
				cout<<"\n\n Data Found @ : "<<flag<<"\n\n";
				return flag;
			}
}
int Book ::insert()
{
	Book 	b;
	Book 	temp;
	int 	index;
			cout<<"\n\n Enter Details Of Book To Be Inserted \n\n";
			b.singleinput();
			cout<<" Enter Index Of Where The Record Should Be Inserted : ";
			cin>>index;
			if(index>size)
			{
				cout<<"\n\n Book Cannot Be Inserted "<<endl;
				return -1;
			}
			else
			{
				for(int i=size;i>=index;i--)
				{
					data[i]=data[i-1];
				}
				data[index]=b.data[0];
				size+=1;
				cout<<"\n\n Book Inserted \n\n";
				return 1;
			}
}
int Book ::delete1()
{
	int 	n;
	int 	flag,bookno1;
	Book 	temp;
		n=size;
		cout<<"\n\n Enter BookNo To Be Deleted : ";
		cin>>bookno1;
		for(int i=0,flag=-1;i<n;i++)
		{
			if(data[i].bookno==bookno1)
			{
				for(int j=i;j<n-1;j++)
				{
					data[j]=data[j+1];
				}
				flag=1;
				n--;
				i--;
			}
		}
		if(flag==-1)
		{
			cout<<"\n\n Book Not Found \n\n";
			return -1;
		}
		else
		{
			cout<<"\n\n Book Deleted \n\n";
			size=n;
			return 1;
		}
}
#include"vector.h"
Vector::Vector()
{
	int 	i;
	dimensions=3;
	data=new int[dimensions];
	for(i=0;i<dimensions;i++)
	{
		data[i]=0;
	}
}
Vector::Vector(int n)
{
	int i;
	dimensions=n;
	data=new int[dimensions];
	for(i=0;i<dimensions;i++)
	{
		data[i]=0;
	}
}
int Vector::input()
{
	int i;
	cout<<"\n\n Vector Input \n\n";
	cout<<"\n\n Enter The Number Of Dimensions : ";
	cin>>dimensions;
	cout<<"\n\n";
	for(i=0;i<dimensions;i++)
	{
		cout<<" Enter Magnitude Of Dimension "<<i+1<<" : ";
		cin>>data[i];
	}
	cout<<"\n\n";
	return 1;
}
int Vector::display()
{
	int i;
	cout<<"\n\n Displaying The Vector \n\n";
	for(i=0;i<dimensions;i++)
	{
		cout<<" Magnitude Of Dimension "<<i+1<<" : "<<data[i]<<"\n";
	}
	cout<<"\n\n";
	return 1;
}
Vector Vector::add(Vector b)
{
	int i;
	cout<<"\n\n Vector Addition \n\n";
	if(dimensions==b.dimensions)
	{
		Vector temp;
		temp.dimensions=dimensions;
		for(i=0;i<dimensions;i++)
		{
			temp.data[i]=data[i]+b.data[i];
		}
		return temp;
	}
	else if(dimensions>b.dimensions)
	{
		Vector temp;
		temp.dimensions=dimensions;
		for(i=0;i<b.dimensions;i++)
		{
			temp.data[i]=data[i]+b.data[i];
		}
		while(i<dimensions)
		{
			temp.data[i]=data[i];
			i++;
		}
		return temp;
	}
	else if(dimensions<b.dimensions)
	{
		Vector temp;
		temp.dimensions=b.dimensions;
		for(i=0;i<dimensions;i++)
		{
			temp.data[i]=data[i]+b.data[i];
		}
		while(i<b.dimensions)
		{
			temp.data[i]=b.data[i];
			i++;
		}
		return temp;
	}
}
Vector Vector::sub(Vector b)
{
	int i;
	cout<<"\n\n Vector Subtraction \n\n";
	if(dimensions==b.dimensions)
	{
		Vector temp;
		temp.dimensions=dimensions;
		for(i=0;i<dimensions;i++)
		{
			temp.data[i]=data[i]-b.data[i];
		}
		return temp;
	}
	else if(dimensions>b.dimensions)
	{
		Vector temp;
		temp.dimensions=dimensions;
		for(i=0;i<b.dimensions;i++)
		{
			temp.data[i]=data[i]-b.data[i];
		}
		while(i<dimensions)
		{
			temp.data[i]=data[i];
			i++;
		}
		return temp;
	}
	else if(dimensions<b.dimensions)
	{
		Vector temp;
		temp.dimensions=b.dimensions;
		for(i=0;i<dimensions;i++)
		{
			temp.data[i]=data[i]-b.data[i];
		}
		while(i<b.dimensions)
		{
			temp.data[i]=b.data[i];
			i++;
		}
		return temp;
	}
}
int Vector::dotproduct(Vector b)
{
	int i;
	cout<<"\n\n Dot Product \n\n";
	if(dimensions==b.dimensions)
	{
		int sum=0;
		cout<<"\n\n Dot Product Can Be Calculated \n\n";
		for(i=0;i<dimensions;i++)
		{
			sum+=data[i]*b.data[i];
		}
		return sum;
	}

}
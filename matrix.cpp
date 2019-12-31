#include"matrix.h"

int Matrix :: input()
{
	cout<<"\n\n Entering The Matrix \n\n";
	cout<<" Enter Number Of Rows :  ";
	cin>>r;
	cout<<" Enter Number Of Columns : ";
	cin>>c;
	cout<<"\n\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<" Enter Data :  ";
			cin>>data[i][j];
		}
		cout<<"\n\n";
	}
	cout<<endl;
	return 1;
}
int Matrix :: display()
{
	cout<<"\n\n Displaying The Matrix \n\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<" "<<data[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	return 1;

}
Matrix Matrix :: add(Matrix b)
{
	Matrix 	temp;
		if((r==b.r)&&(c==b.c))
		{
			cout<<" \n\n Matrix Addition Possible \n\n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					temp.data[i][j]=data[i][j]+b.data[i][j];
				}
			}
		}
		else cout<<"\n\n Matrix Addition Not Possible \n\n ";
		temp.r=r;
		temp.c=c;
		return temp;
}
Matrix Matrix :: sub(Matrix b)
{
	Matrix 	temp;
		if((r==b.r)&&(c==b.c))
		{
			cout<<" \n\n Matrix Subtraction Possible \n\n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					temp.data[i][j]=data[i][j]-b.data[i][j];
				}
			}
		}
		else cout<<"\n\n Matrix Subtraction Not Possible \n\n ";
		temp.r=r;
		temp.c=c;
		return temp;

}
Matrix Matrix :: mul(Matrix b)
{
	Matrix 	temp;
	int 	i,j,k;
		if(c==b.r)
		{
			cout<<"\n\n Matrix Multiplication Possible \n\n";
			for(i=0;i<r;i++)
			{
				for(j=0;j<b.c;j++)
				{
					for(k=0;k<b.r;k++)
					{
						temp.data[i][j]+=data[i][k]*b.data[k][j];
					}
				}
			}
		}
		else cout<<"\n\n Matrix Multiplication Not Possible \n\n";
		temp.r=i;
		temp.c=j;
		return temp;

}
Matrix Matrix :: transpose()
{
	Matrix 		temp;
				for (int i=0;i<c;++i)
				{
	        		for (int j=0;j<r;++j) 
	        		{
	            		temp.data[i][j]=data[j][i];
	        		}
	   			}
	   			temp.r=c;
	   			temp.c=r;
	   			return temp;
}
Matrix :: Matrix()
{
	int 	i;
		r=15;
		c=15;
		data= new int*[r];
		for(i=0;i<r;i++)
		{
			data[i]=new int[c];
		}
		
		for(i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				data[i][j]=0;
			}
		}
}
Matrix :: Matrix(int row,int column)
{

	int 	i;
		data= new int*[r];
		for(i=0;i<row;i++)
		{
			data[i]=new int[column];
		}
		
		for(i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				data[i][j]=0;
			}
		}
}
Matrix :: ~Matrix()
{
		for(int i=0;i<r;i++)
		{
			delete[] data[i];
		}
		delete[] data;
		cout<<"\n\n Deallocated Memory \n\n";
}
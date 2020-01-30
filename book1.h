#ifndef book1_h
#define book1_h
#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>


using namespace std;

class BookDetails
{
	private:
		char 	name[30];
		char	author[30];
		float 	price;
		int 	bookno;
		char	publisher[30];
		int 	publishernumber;
	public :
	        
	friend  class   Library;
	friend  ostream& operator <<(ostream&,BookDetails);
	friend  istream& operator >>(istream&,BookDetails&);
};
class Library
{
	private :
			BookDetails *data;
			int 	size;
	public  :
			int 	input();
			int 	display();
			int 	sort();
			int     insert();
			int 	delete1();
			int 	search(int bookno1);
			Library();
			Library(int n); 
};
#endif

#ifndef stlqueue_h
#define stlqueue_h
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class BookDetails
{
	private:
		string	name;
		string	author;
		float 	price;
		int 	bookno;
		string	publisher;
		int 	publishernumber;
	public :
	        
	friend  class   Library;
	friend  ostream& operator <<(ostream&,BookDetails);
	friend  istream& operator >>(istream&,BookDetails&);
};
class Library
{
	private :
			queue<BookDetails> data;
			int size,maxsize;
	public  :
			int 	input();
			int 	display();
			int     insert();
			int 	delete1();
			Library();
			Library(int n);
};
#endif
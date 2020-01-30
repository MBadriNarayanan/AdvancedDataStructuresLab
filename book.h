#ifndef book_h
#define book_h

#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>


using namespace std;

class BookDetails
{
	public : 
	string 	name;
	string	author;
	float 	price;
	int 	bookno;
	string	publisher;
	int 	publishernumber;
};
class Library
{
	private :
			BookDetails *data;
			int 	size;
	public  :
			int 	input();
			BookDetails singleinput();
			int 	display();
			int 	singledisplay(BookDetails data);
			int 	sort();
			int     insert();
			int 	delete1();
			int 	search(int bookno1);
			Library();
			Library(int n);
};
#endif

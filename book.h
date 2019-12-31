#ifndef book_h
#define book_h
#include<iostream>
#include<stdlib.h>
using namespace std;

class BookDetails
{
	public:
		char 	name[100];
		char	author[100];
		float 	price;
		int 	bookno;
		char 	publisher[100];
		int 	publishernumber;
};
class Book
{
	public :
			BookDetails *data;
			int 	size;
			int 	input();
			int 	display();
			int 	sort();
			int		insert();
			int 	delete1();
			int 	singleinput();
			int 	search(int bookno1);
			Book();
			Book(int n);
};
#endif
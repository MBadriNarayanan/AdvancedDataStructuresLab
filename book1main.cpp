#include"book1.h"
int main()
{
	Library a;
	int 	option,choice;
			do
			{
				cout<<"\n\n\n User Defined Class \n\n\n";
				cout<<" 1. Input And Display \n";
				cout<<" 2. Sort \n";
				cout<<" 3. Insert \n";
				cout<<" 4. Delete \n";
				cout<<" 5. Search \n";
				cout<<" 6. Exit \n";
				cout<<"\n Enter Choice : ";
				cin>>option;
				switch(option)
				{
					case 1 :
							{
								cout<<"\n\n Input and Display \n\n";
								a.input();
								a.display();
								break;
							}
					case 2 :
							{
								cout<<"\n\n Sort \n\n";
								a.input();
								a.display();
								a.sort();
								a.display();
								break;
							}
					case 3 :
							{
								
								cout<<"\n\n Insert \n\n";
								a.input();
								a.display();
								a.insert();
								a.display();
								break;
							}
					case 4 :
							{
								
								cout<<"\n\n Delete \n\n";
								a.input();
								a.display();
								a.delete1();
								a.display();
								break;
							}
					case 5 :
							{
								int  bookno1,temp;
								cout<<"\n\n Search \n\n";
								a.input();
								a.display();
								cout<<"\n\n Enter Book No To Be Searched : ";
								cin>>bookno1;
								temp=a.search(bookno1);
								break;
							}

					default:
							{
								cout<<"\n\n Exiting The Program.....\n\n";
								break;
							} 			
				}
				cout<<"\n\n Do You Want To Continue ( Type 0 Or 1 ) : ";
				cin>>choice;
				cout<<endl<<endl;
			}while(choice);
			cout<<"\n\n The End \n\n";
			return 0;		
}

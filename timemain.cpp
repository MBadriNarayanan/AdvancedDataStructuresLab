#include"time.h"
#include"complex.h"
int main()
{
	Time a;
	int     choice,option;
		cout<<"\n\n\n Time Operations With Operator Overloading \n\n\n";
		do
		{
			cout<<" 1. Input And Display \n";
			cout<<" 2. Addition \n";
			cout<<" 3. Subtraction \n";
			cout<<" 4. Addition Using Any Value \n";
			cout<<" 5. Exit \n";
			cout<<" Enter Choice : ";
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
						Time b,c;
						cout<<"\n\n Addition \n\n";
						a.input();
						a.display();
						b.input();
						b.display();
						c=a+b;
						c.display();
						break;
					}
					case 3 :
					{
						Time b,c;
						cout<<"\n\n Subtraction \n\n";
						a.input();
						a.display();
						b.input();
						b.display();
						c=a-b;
						c.display();
						break;
					}
					case 4 :
					{
						Time c;
						int value;
						cout<<"\n\n Addition Using Any Value \n\n";
						a.input();
						a.display();
						cout<<" Enter The Value To Be Added : ";
						cin>>value;
						c=a*value;
						c.display();
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

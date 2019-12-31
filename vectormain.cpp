#include"vector.h"
int main()
{
		cout<<"\n\n Vectors \n\n";
		int 	option,choice;
		Vector 	a;
		cout<<"\n\n\n Vector Operations \n\n\n";
		do
		{
			cout<<" 1. Input And Display \n";
			cout<<" 2. Addition \n";
			cout<<" 3. Subtraction \n";
			cout<<" 4. Dot Product \n";
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
							Vector b,c;
							cout<<"\n\n Addition \n\n";
							a.input();
							a.display();
							b.input();
							b.display();
							c=a.add(b);
							c.display();
							break;
						}
				case 3 :
						{
							Vector b,c;
							cout<<"\n\n Subtraction \n\n";
							a.input();
							a.display();
							b.input();
							b.display();
							c=a.sub(b);
							c.display();
							break;
						}
				case 4 :
						{
							Vector b;
							cout<<"\n\n Vector Dot Product \n\n";
							a.input();
							a.display();
							b.input();
							b.display();
							cout<<" "<<a.dotproduct(b);
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
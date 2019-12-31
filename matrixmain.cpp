#include"matrix.h"
int main()
{

	int 	option,choice;
	Matrix 	a;
		cout<<"\n\n\n Matrix Operations \n\n\n";
		do
		{
			cout<<" 1. Input And Display \n";
			cout<<" 2. Addition \n";
			cout<<" 3. Subtraction \n";
			cout<<" 4. Multiplication \n";
			cout<<" 5. Transpose \n";
			cout<<" 6. Exit \n";
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
							Matrix b,c;
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
							Matrix b,c;
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
							Matrix b,c;
							cout<<"\n\n Multiplication \n\n";
							a.input();
							a.display();
							b.input();
							b.display();
							c=a.mul(b);
							c.display();
							break;
						}
				case 5 :
						{
							Matrix b;
							cout<<"\n\n Matrix Transpose \n\n";
							a.input();
							a.display();
							b=a.transpose();
							b.display();
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

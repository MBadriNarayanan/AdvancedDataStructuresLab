#include"dijkstra.h"

int main()
{
	
	cout<<"\n\n Dijkstra Algorithm \n\n";

	Graph G;
	string source;
	G.display();
	cout<<"\n\n Enter Source Vertex : ";
    cin>>source;
    cout<<"\n\n";
    G.dijkstra(source);
    cout<<"\n\n";
	cout<<"\n\n The End \n\n";
	return 0;
}
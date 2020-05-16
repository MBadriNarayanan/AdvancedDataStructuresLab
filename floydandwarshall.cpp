#include"floydandwarshall.h"

int main()
{
	
	cout<<"\n\n Floyd And Warshall ALgorithm \n\n";

	cout<<" Floyd \n\n";

	Graph G;

	G.weightmatrix();

	G.floyd();

	cout<<" Warshall \n\n";

	Graph graph;

	graph.adjacencymatrix();

	graph.warshall();

	cout<<"\n\n The End \n\n";

	return 0;

}
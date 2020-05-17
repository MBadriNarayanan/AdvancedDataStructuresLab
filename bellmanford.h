#ifndef bellmanford_h
#define bellmanford_h

#include <iostream>
#include <vector>
using namespace std;

#define max 99

class Node
{
	public:
	string label;
	bool visited;
	int cost;
	string pred;
	Node()
	{
		
	}
	
	Node(string s)
	{
		label = s;	
		visited = false;
		cost = max;
	}	
	
	Node(string s, int cst)
	{
		label = s;	
		visited = false;
		cost = cst;
	}

};	

class Graph
{
	public:

		vector< vector<Node> > graph;
		int n;

		Graph()
		{
			string s;
			cout <<" Enter Number Of Vertices : ";
			cin >>n;
			string t;
			for (int i = 0; i < n; i++)
			{
				vector<Node> singleList;
				cout<<"\n Details For Vertex "<<i + 1 <<"\n";
				cout <<"\n Enter Label Of Node : ";
				cin >>s;
				singleList.push_back(Node(s, 0));
				cout <<"\n Enter Number of Adjacent Nodes : ";
				int n2, cst;
				cin >>n2;
				for (int j = 0; j < n2; j++)
				{
					cout<<"\n Details For Adjacent Node "<<j + 1<<"\n";
					cout <<"\n Enter Label Of Adjacent Node : ";
					cin>>s;
					cout<<"\n Enter Cost : ";
					cin>>cst;
					singleList.push_back(Node(s, cst));
				}
				graph.push_back(singleList);
			}
		}
		
		int display()
		{	
			cout<<"\n\n Displaying Graph Details \n\n";
			for (int i = 0; i < n; i++)
			{
				int s = graph[i].size();
				for (int j = 0; j < s; j++)
				{	
					cout <<" "<<graph[i][j].label<<"  "<< graph[i][j].cost<<"\n";
				}
			}
			cout<<"\n\n";
			return 0;
		}
		int findNode(string l)
		{
			for (int i = 0; i < n; i++)
			{
				if (graph[i][0].label == l)return i;
			}
			return -1;
		}
	
		int bellmanford(string x)
		{
			int y = findNode(x);
			for (int i=0; i<n; i++)
			{
				if (i==y)
				{
					graph[i][0].cost = 0;
				
				}
				else
				{
					graph[i][0].cost = max;
				}
			}
        	for(int k=0;k<n-1;k++)
        	{	
            	for (int i=0; i<n; i++)
            	{
                	int s = graph[i].size();
                	for (int j=1; j<s; j++)
                	{
                    	int c = findNode(graph[i][j].label);
						if (graph[i][j].cost+graph[i][0].cost<graph[c][0].cost)
						{	
							graph[c][0].cost = graph[i][j].cost+graph[i][0].cost;
							graph[c][0].pred = graph[i][0].label;
						}
                	}
            	}
        	}

			for (int i=0; i<n; i++)
        	{
            	cout<<" "<<graph[i][0].label<<" - "<<graph[i][0].cost<<endl;
        	}
        	cout<<endl<<endl;
	}
	
};

#endif
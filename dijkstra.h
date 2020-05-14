#ifndef dijkstra_h
#define dijkstra_h

#include <iostream>
#include <vector>

using namespace std;

#define max 100000000

class Node
{
	public:

	string label;
	int 	cost;

	Node() {}

	Node(string s)
	{
		label = s;
		cost = max;
	}

	Node(string s, int cst)
	{
		label = s;
		cost = cst;
	}
};

class Distance
{
	public:

		string pred;
		string label;
		int cost;

		Distance()
		{
			cost = max;
		}
};

class Graph
{
	public:
			vector< vector<Node> > graph;
			Distance* shortest_path;
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
		shortest_path = new Distance[n];
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
		//int x = graph.size();
		for (int i = 0; i < n; i++)
		{
			if (graph[i][0].label == l)return i;
		}
		return -1;
	}

	int dijkstra(string x)
	{
		cout<<"\n\n The Shortest Path Is \n\n";
		bool visited[1001] = { false };
		int y = findNode(x);
		for (int i = 0; i < n; i++)
		{
			if (i == y)
			{
				shortest_path[i].pred = x;
				shortest_path[i].label = graph[i][0].label;
				shortest_path[i].cost = 0;
			}
			else
			{
				shortest_path[i].pred = x;
				shortest_path[i].label = graph[i][0].label;
				shortest_path[i].cost = max;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << y << endl;
			int s = graph[y].size();
			visited[y] = true;
			for (int j = 1; j < s; j++)
			{
				int c = findNode(graph[y][j].label);
				if (visited[c] == false)
					if (graph[y][j].cost + shortest_path[y].cost < shortest_path[c].cost)
					{
						shortest_path[c].cost = graph[y][j].cost + shortest_path[y].cost;
						shortest_path[c].pred = graph[y][0].label;
					}
			}
			int min = max;
			int minpos = -1;
			for (int j = 0; j < n; j++)
			{
				if (shortest_path[j].cost < min && visited[j]==false)
				{
					min = shortest_path[j].cost;
					minpos = j;
				}
			}
			if (minpos == -1) break;
			y = minpos;
		}

		for (int i = 0; i < n; i++)
		{
			cout <<" "<<shortest_path[i].label<< " - " <<shortest_path[i].pred;
			if (shortest_path[i].cost == max)cout<< " - inf "<< endl;
			else cout<<" - " <<shortest_path[i].cost<< endl;
		}
		return 0;
	}

};

#endif
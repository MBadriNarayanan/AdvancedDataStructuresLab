/*
Includes
1. Prim - graph must be undirected //any vertex can be starting vertex
2. Kruskal - graph must be undirected //needs Disjoint set and priority queue
*/
#ifndef primandkruskal_h
#define primandkruskal_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100000000

class DisjointSet //disjoint set for integers
{
    public:

    int     n; //number of vertices+1 -> we don't consider 0
    int    *s;

    DisjointSet(){}
    DisjointSet(int no)
    {
        n = no+1;
        s = new int[n];
        for (int i=0; i<n; i++)
        {
            s[i] = -1;
        }
    }

    int findParent(int x)
    {
        while (s[x]>=0)
        {
            x = s[x];
        }
        return x;
    }

    void weightedUnion(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (s[u]<s[v])
        {
            s[u]+=s[v];
            s[v] = u;
        }
        else
        {
            s[v]+=s[u];
            s[u] = v;
        }
    }
};

class Graph
{
    public:
            int     n;            //Number of vertices +1  (because we aren't using 0th index)
            int    **adj;        //Adjacency Matrix

            Graph(int num)
            {
                n = num+1;
                adj = new int *[n];
                for (int i=0; i<n; i++)
                {
                    adj[i] = new int[n];
                }
                for (int i=0; i<n; i++)
                {
                    for (int j=0; j<n; j++)
                    {
                        adj[i][j] = MAX;
                    }
                }
            }
            Graph()
            {
                Graph(1000);
            }


            int insert(int from, int to, int cost)
            {
                adj[from][to] = cost;
                return 0;
            }

            int display()
            {
                for (int i=0; i<n; i++)
                {
                    for (int j=0; j<n; j++)
                    {
                        if (adj[i][j]!=MAX)
                        {
                            cout<<" "<<i<<" - "<<j<<" - "<<adj[i][j]<<endl;
                        }
                    }
                    cout<<"\n\n";
                }
        		return 0;
            }

            vector< pair<int, int> > prim()
            {
                int near[n];
                for (int i=0; i<n; i++)
                {
                    near[i] = MAX;
                }
                vector< pair<int, int> > MST;//Finding Minimum Edge
                int min = MAX;
                int mini, minj;
                for (int i=1; i<n; i++)
                {
                    for (int j=i; j<n; j++)
                    {
                        if (adj[i][j]<min)
                        {
                            min = adj[i][j];
                            mini=i;
                            minj=j;
                        }
                    }
                }
                MST.push_back(make_pair(mini, minj));
                near[mini]=near[minj] =0; //setting min edge as 0

                //Storing the closer vertex among the minimum edge with all vertices
                for (int i=1; i<n; i++)
                {
                    if (near[i]!=0)near[i] = (adj[mini][i]<adj[minj][i])?mini:minj;
                }
                for (int z= 1; z<n-2; z++)
                {
                    //Finding connected edge with minimum cost
                    int k = -1;
                    min = MAX;
                    for (int i=1; i<n; i++)
                    {
                        if (near[i]!=0)
                        {
                            if (adj[i][near[i]]<min)
                            {
                                min=adj[i][near[i]];
                                k = i;
                            }
                        }
                    }
                    MST.push_back(make_pair(k, near[k]));

                    //setting new vertex to 0
                    near[k] = 0;

                    //updating closer vertices by checking existing closest to new vertex //In last iteration, this isn't even needed
                    for (int i=1; i<n; i++)
                    {
                        if (near[i]!=0)
                            if (adj[i][k]<adj[i][near[i]])
                                near[i] = k;
                    }
                }
                return MST;
            }

            //When Starting vertex is passed (Almost similar to above method)
            vector<pair<int, int> > prim(int start_vertex)
            {
                int near[n];
                for (int i=0; i<n; i++)
                {
                    near[i] = MAX;
                }
                vector< pair<int, int> > MST;
                //Finding Minimum Edge
                int min = MAX;
                int mini = start_vertex, minj;
                for (int i=1; i<n; i++)
                {
                    if (adj[mini][i]<min)
                    {
                        min = adj[mini][i];
                        minj = i;
                    }
                }
                MST.push_back(make_pair(mini, minj));
                near[mini]=near[minj] =0; //setting min edge as 0

                //Storing the closer vertex among the minimum edge with all vertices
                for (int i=1; i<n; i++)
                {
                    if (near[i]!=0)
                        near[i] = (adj[mini][i]<adj[minj][i])?mini:minj;
                }
                for (int z= 1; z<n-2; z++)
                {
                    //Finding connected edge with minimum cost
                    int k = -1;
                    min = MAX;
                    for (int i=1; i<n; i++)
                    {
                        if (near[i]!=0)
                        {
                            if (adj[i][near[i]]<min)
                            {
                                min=adj[i][near[i]];
                                k = i;
                            }
                        }
                    }
                    MST.push_back(make_pair(k, near[k]));

                    //setting new vertex to 0
                    near[k] = 0;

                    //updating closer vertices by checking existing closest to new vertex //In last iteration, this isn't even needed
                    for (int i=1; i<n; i++)
                    {
                        if (near[i]!=0)
                            if (adj[i][k]<adj[i][near[i]])
                                near[i] = k;
                    }
                }
                return MST;
            }
            
            //User-defined comparator for comparing edges based on cost (used in kruskal)
            class compare
            {    
                public:
                bool operator()(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2) 
                {
                    return p1.first>p2.first;
                }
            };
        
            vector< pair<int, int> > kruskal()
            {
                //syntax for defining minheap based on cost
                priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > >, compare > pq; 
                
                vector<pair<int, int> > MST;
                for (int i=1; i<n; i++)
                {
                    for (int j=i; j<n; j++)
                    {
                        if (adj[i][j]!=MAX)pq.push(make_pair(adj[i][j], make_pair(i, j)));
                    }
                }
                DisjointSet d(n);
                pair<int, int> p;
                while (pq.size())
                {
                    p = (pq.top()).second; pq.pop();
                    if (d.findParent(p.first)!=d.findParent(p.second))
                    {
                        MST.push_back(p);
                        d.weightedUnion(p.first, p.second);
                    }
                }
                return MST;
            }

            void printMST(string x, vector<pair<int, int> > MST)
            {
                cout<<" ------------------------------------------ "<<endl<<endl<<endl;
                cout<<" "<<x<<"'s MST : "<<endl;
                cout<<" From \t  To \t  Cost "<<endl;
                for (auto edge:MST)
                {
                    cout<<" "<<edge.first<<" - "<<edge.second<<" - "<<adj[edge.first][edge.second]<<endl;
                }
                cout<<" ------------------------------------------ "<<endl<<endl<<endl;
            }

}; 

#endif
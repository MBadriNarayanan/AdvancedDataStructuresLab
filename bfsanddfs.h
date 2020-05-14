#ifndef bfsanddfs_h
#define bfsanddfs_h

#include<iostream>
#include<list>
#include<string>

using namespace std;

template<class T>
class Graph
{
    int         no_of_vertices;
    list<int>   *adj;

    public:

                Graph(int v)
                {
                    no_of_vertices = v;
                    adj = new list<int>[no_of_vertices];
                }
                int addEdge(T v1, T v2)
                {
                    if(isalpha(v1)) 
                    {
                        if(v1 >= 65 && v1 <= 90)  
                        {
                            int v3 = (int)v1-65;
                            int v4 = (int)v2-65;
                            adj[v3].push_back(v4);
                        }
                        else if(v1 >= 97 && v1 <= 122)
                        {
                            int v3 = (int)v1-97;
                            int v4 = (int)v2-97;
                            adj[v3].push_back(v4);
                        }
                
                    }
                    else adj[v1].push_back(v2); // Nodes are numbers
                }
                int BFS(T source)
                {
                    int     flag = 0;
                    int     i,vertex, source1;
                    list<int>   Q;
                    list<int> :: iterator it;
                    bool *visited = new bool[no_of_vertices];
                    for(i=0;i<no_of_vertices;i++)
                    {
                            visited[i] = false; //Initially none visited
                    }
                    if(isalpha(source))
                    {
                        if(source>=65 && source<=90)
                        {
                            flag=1;
                            source1= (int)source-65;
                        }
                        else if(source>=97 && source<=122)
                        {
                            flag=2;
                            source1= (int)source-97;
                        }
                        visited[source1] = true;
                        Q.push_back(source1);
        
                    }
                    else
                    {
                        visited[source] = true; //At source
                        Q.push_back(source);
                    }
                    while(!Q.empty()) // Popping from Queue
                    {
                        vertex = Q.front();
                        Q.pop_front();
                        if(flag==1)
                        {
                            cout<<" "<<char(vertex+65)<<" ";
                        }
                        else if(flag==2)
                        {
                            cout<<" "<<char(vertex+97)<<" ";
                        }
                        else cout<<" "<<vertex<<" ";
                        for(it = adj[vertex].begin();it!=adj[vertex].end();it++)
                        {
                            if(!visited[*it])
                            {
                                visited[*it] = true;
                                Q.push_back(*it);
                            }
                        }
                    }
                    return 0;
                }
                int DFS(T source)
                {
                    int     flag,source1;
                    int     i,vertex;
                    bool    *visited = new bool[no_of_vertices];
                    list<int> Stack;
                    list<int> :: iterator it;
                    flag = 0;
                    for(i=0;i<no_of_vertices;i++)
                    {
                        visited[i] = false; //Initially none visited
                    }
                    if(isalpha(source))
                    {
                        if(source>=65 && source<=90)
                        {
                            flag = 1;
                            source1= (int)source-65;
                        }

                        else if(source>=97 && source<=122)
                        {
                            flag = 2;
                            source1= (int)source-97;
                        }
                        visited[source1] = true;
                        Stack.push_back(source1);
                    }
                    else
                    {
                        visited[source] = true; //At source
                        Stack.push_back(source);
                    }

                    while(!Stack.empty()) // Popping from Queue
                    {
                        vertex = Stack.back();
                        Stack.pop_back();
                        if(flag==1)
                        {
                            cout<<" "<<char(vertex+65)<<" ";
                        }

                        else if(flag==2)
                        {
                            cout<<" "<<char(vertex+97)<<" ";
                        }

                        else cout<<" "<<vertex<<" ";
                        for(it = adj[vertex].begin();it!=adj[vertex].end();it++)
                        {
                            if(!visited[*it])
                            {
                                visited[*it] = true;
                                Stack.push_back(*it);
                            }
                        }
                    }
                    return 0;
                }
};
#endif
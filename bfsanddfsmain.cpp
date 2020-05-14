#include "bfsanddfs.h"

int main()
{
    int     choice;
            do
            {
                    cout<<"\n\n Creating The Graph \n\n";
                    cout<<" 1. Character \n";
                    cout<<" 2. Integer \n";
                    cout<<" Enter Choice : ";
                    cin>>choice;
                    cout<<endl<<endl;
                    if(choice == 1)
                    {
                        int     n;
                        char    vertex1,vertex2,source;
                        int     vertexcontinue;
                                    cout<<" Enter Number Of Vertices : ";
                                    cin>>n;
                        Graph<char> G(n); 
                                    cout<<" Enter Source Vertex : ";
                                    cin>>source;
                                    cout<<endl<<endl;
                                    do
                                    {
                                        cout<<"\n Enter Vertex 1 Of Edge : ";
                                        cin>>vertex1;
                                        cout<<"\n Enter Vertex 2 Of Edge : ";
                                        cin>>vertex2;
                                        G.addEdge(vertex1,vertex2);
                                        cout<<"\n Do You Have Any More Edges ( Type 0 Or 1 To Continue) : ";
                                        cin>>vertexcontinue;

                                    }while(vertexcontinue == 1);
                                    cout<<"\n\n BFS & DFS Graph Traversal \n\n";
                                    cout<<" 1. BFS \n";
                                    cout<<" 2. DFS \n";
                                    cout<<"\n\n BFS \n\n";
                                    G.BFS(source);
                                    cout<<endl<<endl;
                                    cout<<"\n\n DFS \n\n";
                                    G.DFS(source);
                                    cout<<endl<<endl;
                    }
                    if(choice == 2)
                    {
                        int         n;
                        int         vertex1,vertex2,source;
                        char        vertexcontinue;
                                    cout<<" Enter Number Of Vertices : ";
                                    cin>>n;
                        Graph<int> G1(n); 
                                    cout<<" Enter Source Vertex : ";
                                    cin>>source;
                                    cout<<endl<<endl;
                                    do
                                    {
                                        cout<<"\n Enter Vertex 1 Of Edge : ";
                                        cin>>vertex1;
                                        cout<<"\n Enter Vertex 2 Of Edge : ";
                                        cin>>vertex2;
                                        G1.addEdge(vertex1,vertex2);
                                        cout<<"\n Do You Have Any More Edges ( Type Y Or N To Continue) : ";
                                        cin>>vertexcontinue;
                                        
                                    }while(vertexcontinue == 'Y');
                                    cout<<"\n\n BFS & DFS Graph Traversal \n\n";
                                    cout<<" 1. BFS \n";
                                    cout<<" 2. DFS \n";
                                    cout<<"\n\n BFS \n\n";
                                    G1.BFS(source);
                                    cout<<endl<<endl;
                                    cout<<"\n\n DFS \n\n";
                                    G1.DFS(source);
                                    cout<<endl<<endl;
                    }

                    cout<<"\n Do You Want To Continue ( Type 0 Or 1) : ";
                    cin>>choice;

            }while(choice == 1);

            cout<<"\n\n The End \n\n";

            return 0;
}
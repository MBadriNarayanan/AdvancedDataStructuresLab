#include"topologicalsort.h"

int main() 
{ 
    cout<<"\n\n Topological Sort \n\n";

    int n;

    cout<<" Enter Number Of Vertices : ";
    cin>>n;

    Graph G(n);
    

    int vertexcontinue,vertex1,vertex2;

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
  
    cout << "\n\n Topological Sort Of Given Graph \n\n"; 

    G.topologicalSort(); 

    cout<<"\n\n The End \n\n";
  
    return 0; 
}
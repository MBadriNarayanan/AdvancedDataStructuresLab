#include"primandkruskal.h"

int main()

{
    int from, to, x, n, cost, edgecount;
    int option;

    do
    {

        cout <<"\n\n Prims & Kruskal Algorithms \n\n";
        cout<<" 1. Prims \n";
        cout<<" 2. Kruskal \n";
        cout<<"\n Enter Number Of Vertices : ";
        cin >>n;
        cout << "\n Enter Number Of Edges : ";
        cin >>edgecount;

        Graph g(n);
    
        for (int i = 0; i < edgecount; i++)
        {
            cout<<"\n Details For Edge "<<i+1<<"\n";
            cout<<"\n Enter From : ";
            cin>>from;
            cout<<"\n Enter To : ";
            cin>>to;
            cout<<"\n Enter Cost : ";
            cin>>cost;
            g.insert(from, to, cost);
            g.insert(to, from, cost);
        }
        auto MST = g.kruskal();
        g.printMST(" Kruskal ", MST);
        MST = g.prim();
        g.printMST(" Prims ", MST);
        cout<<"\n\n Prims Algorithm With A Starting Vertex \n\n";
        cout<<"\n Enter Starting Vertex : ";
        cin>>x;
        MST = g.prim(x);
        g.printMST(" Prims ", MST);
        cout<<" Do You Want To Continue (Type 0 Or 1 ) : ";
        cin>>option;
    }while(option == 1);
    
    cout<<"\n\n The End \n\n";
    return 0;
}
#ifndef floydandwarshall_h
#define floydandwarshall_h

#include<iostream>
#include <algorithm> 
using namespace std;

#define inf 10000

class Graph
{
    public:

    int     n;
    int     **mat;

    Graph()
    {
        cout<<" Enter Number Of Vertices : ";
        cin>>n; 
        mat = new int*[n];
        for(int i = 0; i < n; i++)
        {
            mat[i] = new int[n];
        }
    }

    int weightmatrix()
    {
        
        cout<<"\n\n Creating Weight Matrix \n\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout<<" Enter Value ( For Infinity Enter -1) : ";
                cin>>mat[i][j];
                if(mat[i][j] == -1)mat[i][j] = inf;
            }
            cout<<"\n";
        }    

        cout<<"\n\n";
        return 0;
    }

    int adjacencymatrix()
    {
        
        cout<<"\n\n Creating Adjacency Matrix \n\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout<<" Enter Value : ";
                cin>>mat[i][j];
            }
            cout<<"\n";
        }    

        cout<<"\n\n";
        return 0;
    }

    int warshall() 
    {
        int i,j,k;
        for(k = 0; k < n; k++)
        {
            for(j = 0; j < n; j++)
            {
                for(i = 0; i < n; i++)
                {
                    mat[i][j] = mat[i][j] | (mat[i][k] & mat[k][j]);
                }
            }
        }

        cout<<"\n\n Transitive Closure \n\n";
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cout<<" "<<mat[i][j]<<" ";
            }

            cout<<endl;
        }
        cout<<"\n\n";
        return 0;
    }
    int floyd() 
    {
        int k, j, i;
        for(k = 0; k < n; k++)
        {
            for(j = 0; j < n; j++)
            {
                for(i = 0; i < n; i++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }


        cout<<"\n\n Distance Matrix \n\n";
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)    
            {
                cout<<" "<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<"\n\n";
        return 0;
    }
};

#endif

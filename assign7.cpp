//============================================================================
// Name : 21116.cpp
// Author : aditya darade
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
    int v, e;
    int **adj;

public:
    graph(int v_, int e_)
    {
        v = v_;
        e = e_;

        adj = new int *[v];

        for (int i = 0; i < v; i++)
        {
            adj[i] = new int[v];
        }

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void create()
    {
        int u, v, w;
        for (int i = 0; i < e; i++)
        {
            cout << "Enter edge between :- ";
            cin >> u >> v;

            cout << "Enter weight between " << u << " & " << v << ":-  ";
            cin >> w;
            adj[u][v] = w;
            adj[v][u] = w;
            
        }
    }

    void display()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void krushkal()
    {
        int **mst = new int *[v];

        for (int i = 0; i < v; i++)
        {
            mst[i] = new int[v];
        }

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                mst[i][j] = 0;
            }
        }

        int *vis = new int[v];
        int *parent = new int[v];

        // set false  as default --- AND themself as default parent.
        for (int j = 0; j < v; j++)
        {
            vis[j] = 0;
            parent[j] = j; 
        }

        // for undirected make it "i<2*e" that's it------------------ for directed (i < e )main logic as it is
        for (int i = 0; i < 2*e; i++)
        {
            int min = 9999;
            int a, b;

            // Finding minimum edge from matrix
            for (int j = 0; j < v; j++)
            {
                for (int k = 0; k < v; k++)
                {
                    if (adj[j][k] != 0 && adj[j][k] < min)
                    {
                        min = adj[j][k];
                        a = j;
                        b = k;
                    }
                }
            }

            adj[a][b] = 0;
            adj[a][b] = adj[b][a] = 0;                    //------> For undirected grapgh

            // adding that min edge in mst in not already included.
            addedge(a, b,min, parent, mst);
        }

        cout << "Printing MST:- \n";
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << mst[i][j] << " ";
            }
            cout << endl;
        }
    }

    int findparent(int x, int *parent)
    {
        int t = x;
        while (t != parent[t])
        {
            t = parent[t];
        }
        return t;
    }

    void addedge(int a, int b,int w, int *parent, int **mst)
    {
        int p1 = findparent(a, parent);
        int p2 = findparent(b, parent);

        if (p1 == p2)
            return;

        // if (rank[p1] == rank[p2])
        // {
        //     parent[p2] = p1;
        //     rank[p1]++;
        // }
        // else if (rank[p1] > rank[p2])
        // {
        //     parent[p2] = p1;
        // }
        // else
        // {
        //     parent[p1] = p2;
        // }

        parent[p2] = p1;
        mst[a][b] = w;
        //mst[a][b] = mst[b][a] = w; ------> for undirected 
    }

    void prim()

    {

        int *key = new int[v];
        int *parent = new int[v];
        bool *MST = new bool[v];

        for (int i = 0; i < v; i++)
        {
            key[i] = 99999;
            parent[i] = -1;
            MST[i] = false;
        }

        int src;

        cout << "Enter source vertex? ";

        cin >> src;

        key[src] = 0;

        for (int i = 0; i < v; i++)
        {
            // key madhe jaun minimum
            int k = 99999, mi;

            for (int j = 0; j < v; j++)
            {
                if (MST[j] != true && key[j] < k)
                {

                    k = key[j];

                    mi = j;
                }
            }

            // MST[min] = true

            MST[mi] = true;

            // traverse neighbours
            for (int g = 0; g < v; g++)
            {
                if (adj[mi][g] != 0)
                {
                    int s = adj[mi][g];

                    if (s < key[g] && MST[g] != true)
                    {
                        key[g] = s;

                        parent[g] = mi;
                    }
                }
            }
        }


        int **mst = new int *[v];
        for (int i = 0; i < v; i++)
        {
            mst[i] = new int[v];
        }

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                mst[i][j] = 0;
            }
        }

        for (int i = 1; i < v; i++)
        {
            int p = parent[i];
    
            mst[p][i] = key[i];
        }

        cout << "Printing MST:- \n";
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << mst[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void)

{

    graph g(7 , 9);

    g.create();

    g.display();
    g.prim();

    g.krushkal();

    return (0);
}
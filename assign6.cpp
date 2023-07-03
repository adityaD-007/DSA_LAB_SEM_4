#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class node
{
    friend class graph;
    int v;
    node *next;

public:
    node(int v = 0)
    {
        next = NULL;
        this->v = v;
    }
};

class graph
{
    int v, e;
    node **adj;
    string *s;

public:
    graph(int v_, int e_)
    {
        v = v_;
        e = e_;
        adj = new node *[v];
        s = new string[v];
        for (int i = 0; i < v; i++)
        {
            adj[i] = NULL;
        }
    }

    void create()
    {

        cout << endl
             << endl;
        while (e--)
        {
            cout << "Enter source & destination of edge :- ";
            int a, b;
            cin >> a >> b;

            if (adj[a] == NULL)
            {
                adj[a] = new node(b);
            }
            else
            {
                node *temp = adj[a];
                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = new node(b);
            }
        }
    }

    void display()
    {
        for (int i = 0; i < v; i++)
        {
            if (adj[i] != NULL)
            {
                cout << i << " -> ";
                node *temp = adj[i];
                while (temp != NULL)
                {
                    cout << temp->v << " , ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }

    void bfs()
    {

        queue<int> q;
        bool *visited;
        visited = new bool(v);

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        int src;
        cout << "Enter the src node :- ";
        cin >> src;
        q.push(src);
        int temp;
        cout << "\nPrinting bsf :- \n";
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (visited[temp])
                continue;

            cout << temp << " ";
            visited[temp] = true;

            node *t = adj[temp];
            while (t != NULL)
            {
                if (visited[t->v] == false)
                    q.push(t->v);

                t = t->next;
            }
        }
        cout << endl;
    }

    void dfs()
    {

        int src;
        cout << "enter the src :- ";
        cin >> src;
        stack<int> st;
        bool *visited;
        visited = new bool(v);
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        st.push(src);
        cout << "\nprinting DFS :- \n";
        int t;

        while (!st.empty())
        {
            t = st.top();
            st.pop();
            if (visited[t])
                continue;
            cout << t << " ";
            visited[t] = true;

            node *temp = adj[t];

            while (temp != NULL)
            {
                if (visited[temp->v] == false)
                {
                    st.push(temp->v);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void Rdfs()
    {

        bool *visited;
        visited = new bool(v);

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        int src;
        cout << "enter the src :- ";
        cin >> src;

        cout << "printing DFS :- \n";

        helper(src, visited);
        cout << endl;
    }

    void helper(int vertex, bool *visited)
    {
        if (visited[vertex] == true)
            return;

        cout << vertex << "  ";
        visited[vertex] = true;

        node *temp = adj[vertex];

        while (temp != NULL)
        {

            if (visited[temp->v] == false)
            {
                helper(temp->v, visited);
            }

            temp = temp->next;
        }
    }
};
int main()
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

    cout << "enter number of vertex and number of edges :- ";
    int v, e;
    cin >> v >> e;
    graph g1(v, e);
    g1.create();
    g1.display();
    cout << "===============================================\n";
    g1.bfs();
    cout << "===============================================\n";
    g1.dfs();
    return 0;
}
//============================================================================
// Name        : 21116A.cpp
// Author      : aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
using namespace std;

class node
{
    friend class obst;
    int data;
    node *left;
    node *right;

public:
    node(int x = 0)
    {
        data = x;
        left = right = NULL;
    }
};

class obst
{
    double *p; // successful probability
    double *q; // unsucessful probaabilty array

    node *root;

    int size;

    double w[5][5]; // matrix for weights -----size is ... ( size +1 )that is  4 + 1
    double c[5][5]; // matrix for costs
    double r[5][5]; // matrix for roots

public:
    obst(int x = 4)
    {
        root = NULL;
        size = x;

        p = new double[size + 1]; 
        q = new double[size + 1];

        for (int i = 0; i <= size; i++)
        {
            p[i] = q[i] = 0.0;
        }
    }

    void fillArr()
    {

        cout << "Enter " << size << " the successful probabilities :-\n";
        for (int i = 1; i <= size; i++)
        {
            cin >> p[i];
        }

        cout << "Enter " << size + 1 << "the unsuccessful probability :- \n";
        for (int i = 0; i <= size; i++)
        {
            cin >> q[i];
        }
        cout << "-------------------------------------------------------------------------\n";
    }

    void create()
    {

        // setting all matrix default 0.
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= size; j++)
            {
                w[i][j] = r[i][j] = c[i][j] = 0;
            }
        }

        // Making matrix of weights of all.

        int diff = 0; //-------------------------------------- variable for keeping difference between i and j --- diff = j-i
        while (diff <= size)
        {

            int i = 0, j = i + diff;

            while(j <= size)
            {
                if (i == j)
                { //----------------------------------  for same i & j weight is unsuccessful probability

                    w[i][j] = q[i];
                }
                else
                {
                    w[i][j] = w[i][j - 1] + p[j] + q[j]; // ----formula for weight (theory part it is)
                }
                i++;
                j = i + diff;
            }

            diff++;
        }

        // Making matrix of costs and roots ............

        diff = 0; // -------------------------------------------variable for keeping difference between i and j --- diff = j-i
        while (diff <= size)
        {

            int i = 0, j = i + diff;

            while (j <= size)
            {
                if (i == j)
                { // same i & j cost is 0
                    r[i][j] = c[i][j] = 0;
                }
                else
                {
                    // this is Method to find cost ...... formula is  c[i , j] = min( c[ i , k-1] + c[k,j] ) for k ...( i < k <= j ) !!!
                    double cost = 99999.9999;
                    for (int k = i + 1; k <= j; k++)
                    {
                        if (cost > c[i][k - 1] + c[k][j])
                        {
                            c[i][j] = c[i][k - 1] + c[k][j];
                           
                            cost = c[i][k - 1] + c[k][j];

                            r[i][j] = k;
                        }
                    }
                    c[i][j] += w[i][j];
                }
                
                i++;
                j = i + diff;
            }
            diff++;
        }

        // Just printing all fakt barobr ahet ki nahi bagayla.
        diff = 0;
        while (diff <= size)
        {
            int i = 0, j = i + diff;

            while (j <= size)
            {
                cout << "{ (" << i << " " << j << ") = " << w[i][j] << " , " << c[i][j] << " , " << r[i][j] << " }----";

                i++;
                j = i + diff;
            }
            cout<< endl << endl ;

            diff++;
        }

        cout << endl;
        cout << endl;

        this->root = makeTree(0, 4);

        cout << "\nPrinting inorder\n";
        inorder(root);
        cout << "\nPrinting PreOrder\n";
        preorder(root);
    }


    node *makeTree(int i, int j)
    { //---------------------------- fakt recurrsive call sagla kam te create function madhe zalay
        if (i == j)
            return NULL;


        int k = r[i][j]; //----------- taking root from matrix of roots

        node *t = new node(k);

        t->left = makeTree(i, k - 1);
        t->right = makeTree(k, j);

        return t;
    }

    void inorder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }

        inorder(temp->left);
        cout << temp->data << " , ";
        inorder(temp->right);
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        
        cout << temp->data << " , ";
        inorder(temp->left);
        inorder(temp->right);
    }
};

int main()
{

    obst t1;

    t1.fillArr();
    t1.create();
    return 0;
}
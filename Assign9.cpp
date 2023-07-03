#include <bits/stdc++.h>
using namespace std;

class node
{
    int data, height;
    node *left, *right;
    friend class AVL;

public:
    node(int d)
    {
        data = d;
        height = 1;
        left = right = NULL;  
    }
};

class AVL
{
public:
    node *Root;

public:
    AVL()
    {
        Root = NULL;
    }

    int H(node *t)
    {
        if (t == NULL)
            return 0;

        return t->height;
    }

    signed int getBalance(node *r)
    {
        if (r == NULL)
            return 0;

        return (H(r->left) - H(r->right));
    }

    node *RightRotate(node *t)
    {

        node *x = t->left;

        t->left = x->right;

        x->right = t; 

        t->height = max(H(t->left), H(t->right)) + 1 ;

        x->height = max(H(x->left), H(x->right)) + 1 ;

        return x;
    }

    node *LeftRotate(node *t)
    {
        node *x = t->right;

        t->right = x->left;
        x->left = t;

        t->height = max(H(t->left), H(t->right)) + 1;

        x->height = max(H(x->left), H(x->right)) + 1;

        return x;
    }

    node *insert(node *root, node *neww)
    {

        if (root == NULL)
        {
            root = neww;
            return root;
        }
        if (root->data > neww->data)
        {
            root->left = insert(root->left, neww);
        }
        else if (root->data < neww->data)
        {
            root->right = insert(root->right, neww);
        }
        else
        {
            return root;
        }

        root->height = max(H(root->left), H(root->right)) + 1;

        signed int bf = getBalance(root);
 
        if (bf > 1 && neww->data < root->left->data)
        {
            return RightRotate(root);
        }
        if (bf > 1 && neww->data > root->left->data)
        {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
        if (bf < -1 && neww->data > root->right->data)
        {
            return LeftRotate(root);
        }
        if (bf < -1 && neww->data < root->right->data)
        {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }

        root->height = max(H(root->left), H(root->right)) + 1;

        return root;
    }

    void inorder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }

        inorder(temp->left);
        cout << "( " << temp->data << " , " << temp->height << " ) -- ";
        inorder(temp->right);
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << "( " << temp->data << " , " << temp->height << " ) -- ";
        preorder(temp->left);

        preorder(temp->right);
    }

    void level()
    {
        queue<node *> q;
        q.push(Root);
        q.push(NULL);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                cout << temp->data<< "     ";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
};

int main()
{

    AVL t1;

    t1.Root = t1.insert(t1.Root, new node(15));
    t1.Root = t1.insert(t1.Root, new node(27));
    t1.Root = t1.insert(t1.Root, new node(100));
    t1.Root = t1.insert(t1.Root, new node(500));
    t1.Root = t1.insert(t1.Root, new node(1000));

    t1.preorder(t1.Root);
    cout << "\n\n------------------------------\n\n";
    t1.level();

    return 0;
}
//============================================================================
// Name        : assignment3.cpp
// Author      : aditya darade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	friend class TBST;
	int data;
	node* left,*right; 
	bool lt , rt;
public:
	node(int d = 0){
		data = d;
		left = right = NULL;
		lt = rt = 0;
	}
};
// lt/rt == 1 means there is child for that node ---- left for lt and right for rt

// lt/rt == 0 means no child theres a thread present ---- left for lt and right for rt
class TBST{
	node* root;
	node* header;
public:
	TBST(){
		root = header = NULL;
	}

	void insert(int d){
		node* child = new node(d);
		if(root == NULL ){
			header = new node(-1);
			root = child;
			root->left = root->right = header;
			return;
		}
		node* parent = root;

		while(1){
			if(parent->data >= d && parent->lt == 1){
				parent = parent->left;
			}else if(parent->data < d && parent->rt == 1){
				parent = parent->right;
			}else{
				break;
			}
		}

		if(parent->data >= d){
			child->left = parent->left;
			child->right = parent;

			parent->left = child;
			parent->lt = 1;
		}else{
			child->left = parent;
			child->right = parent->right;

			parent->right = child;
			parent->rt = 1;
		}
	}

	node* inSucc(node* ptr)
	{
		if (ptr->rt == 0)
			return ptr->right;
	
		ptr = ptr->right;
		while (ptr->lt == 1)
			ptr = ptr->left;
	
		return ptr;
	}
	

    node* leftmost(node* n){
        if (n == NULL)
            return NULL;

        while (n->lt != 0)
            n = n->left;
			
        return n;
    }

    void inOrder(){
		if(root== NULL){
			cout<<"Empty Tree\n";
			return;
		}
        node* cur = leftmost(root);
        cout<<"Printing Inorder :- ";
        while (cur != header) {
            cout<<cur->data<<" ";

            if (cur->rt == 0)
                cur = cur->right;
            else
                cur = leftmost(cur->right);
        }
        cout<<endl;
    }

	void preorder(){
		if(this->root == NULL){
			cout<<"Empty Tree\n";
			return;
		}
		cout<<"Printing Preorder :- ";
		node* temp = root;

		while(temp != header){
			cout<<temp->data<<" ";
			if(temp->lt == 1){
				temp = temp->left;
			}else if(temp->rt){
				temp = temp->right;
			}else{
				if(temp->right == header) break;
				while(temp->rt == 0) temp = temp->right;

				temp = temp->right;

			}
		}
		cout<<endl;
	}

	void find(int key , node* &prev , node* &curr){
		prev = NULL;
		curr = root;

		while(curr != header ){
			if(curr->data == key){
				return;
			}
			prev = curr;
			if(curr->data < key && curr->lt){
				curr = curr->right;
			}else if(curr->data > key && curr->rt){
				curr = curr->left;
			}else{
				curr = prev = NULL;
				cout<<"Data Not Found !!\n";
				return;
			}
		}
		curr = prev = NULL;
		cout<<"Data Not Found !!\n";
	}

	void deletenode(int key){
		if(this->root == NULL){
			cout<<"Empty Tree\n";
			return;
		}
		node* prev = NULL , *curr = NULL;
		find(key , prev , curr);
		 
		if(curr == NULL){
			return ;
		}

		//both children
		if(curr->lt && curr->rt){
    		node* succ = inSucc(curr);
 
    		int d = succ->data;
 
			deletenode(d);
			curr->data = d;
			

		}else if(curr->lt){ // only left children
			node* child = curr->left; 
			if (prev == NULL){
				root = child;
				return;
			}
			if (curr == prev->left)
				prev->left = child;
			else
				prev->right = child;

			while(child->rt == 1) child = child->right;

			child->right = curr->right;


		}else if(curr->rt){ // only right children
			node* child = curr->right; 
			if (prev == NULL){
				root = child;
				return;
			}
			if (curr == prev->left)
				prev->left = child;
			else
				prev->right = child;

			while(child->lt == 1) child = child->left;

			child->left = curr->left;

			

		}else{ // leaf node
			if(prev == NULL) {
				this->root = NULL;
				return;
			}else if (curr == prev->left) {
				prev->lt = 0;
				prev->left = curr->left;
    		}
			else {
				prev->rt = 0;
				prev->right = curr->right;
			}

			delete curr;
		}

	}
};

int main() {

	TBST t1;
	while(1){
		cout<<"Enter data :- ";
		int n;
		cin>>n;
		if( n == -1) break;
		t1.insert(n);
	}
    t1.inOrder();

	t1.deletenode(50);
	t1.inOrder();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
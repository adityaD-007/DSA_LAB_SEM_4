//============================================================================
// Name        : assignment1.cpp
// Author      : aditya darade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<queue>

class node{
	friend class BST;
	string word , meaning;
	node* left , *right;
public:
	node(string a="",string b=""){
		word = a;
		meaning = b;
		left = right = NULL;
	}
};

class BST{
public:
	node* root;
public:
	BST(){
		this->root = NULL;
	}

	void print(node* temp){
		if(temp == NULL) return;

		print(temp->left);
		cout<<"Data is:- "<<temp->word<<" -> "<<temp->meaning<<endl;
		print(temp->right);
	}

	void rprint(node* temp){
			if(temp == NULL) return;

			print(temp->right);
			cout<<"Data is:- "<<temp->word<<" - "<<temp->meaning<<endl;
			print(temp->left);

	}



    void level(){
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node* temp = q.front();
            q.pop();

            if(temp == NULL){
                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }else{
                cout<<temp->word<<"     ";
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

        }
    }
	void insert(string word , string meaning){
		node* new_node = new node(word , meaning);
		if(root == NULL){
			root = new_node ;
		}
		else {
			node* curr = root ;
			node* parent = NULL;
			while(curr!=NULL){
				if(word<curr->word){
					parent = curr ;
					curr = curr -> left ;
				}
				else{
					parent = curr ;
					curr = curr -> right ;
				}
			}
			if(word < parent->word){
				parent->left = new_node ;
			}
			else{
				parent->right = new_node ;
			}
		}
	}

	node* search(string key){
		node* curr = root ;
		int counter = 0 ;
		while(curr!=NULL){
			counter++ ;
			if(curr->word == key){
				cout<<"the element found after - "<<counter<<" iterations"<<endl;
				return curr ;
			}
			else if (key < curr ->word ){
				curr = curr->left ;
			}
			else{
				curr = curr->right ;
			}
		}
		return NULL ;
	}

	void update(string key , string new_meaning){
			node* curr = root ;
			while(curr!=NULL){
				if(curr ->word == key){
					curr->meaning = new_meaning ;
					return;
				}
				else if (key < curr ->word ){
					curr = curr->left ;
				}
				else{
					curr = curr->right ;
				}
			}
			cout<<"the element not found"<<endl ;
		}

void deletenode( string key){
		node* curr = root , *parent = NULL;
		//finfing the node
		while(curr!=NULL){
			if(curr->word == key){
				break;
			}
			else if (key < curr ->word ){
				parent = curr;
				curr = curr->left ;
			}
			else{
				parent = curr;
				curr = curr->right ;
			}
		}

		//if not found
		if(curr == NULL){
			cout<<"Not found"<<endl;
			return;
		}

  		//case 1:- leaf node
		if(curr->left == NULL && curr->right == NULL){
			if(parent == NULL) this->root = NULL;

			if(parent->left == curr) parent->left = NULL;
			else{
				parent->right = NULL;
			}
			delete curr;
			return;
		}
		//case2:- node with 2 child
		if(curr->left != NULL && curr->right != NULL){

			node* temp = curr->right;
			while(temp->left != NULL){
				temp = temp->left;
			}
			string s = temp->word;
			deletenode(s);
			curr->word = s;
			return;
		}
		//case3:- only left child
		if(curr->left != NULL){
			if(parent == NULL) this->root = curr->left;

			if(parent->left == curr) parent->left = curr->left;
			else{
				parent->right = curr->left;
			}
		}else{
			//only right child
			if(parent == NULL) this->root = curr->right;

			if(parent->left == curr) parent->left = curr->right;
			else{
				parent->right = curr->right;
			}
		}
	}
};

int main() {

	BST t1;
	t1.insert("e" , "1");
	t1.insert("a" , "2");
	t1.insert("g" , "3");
	t1.insert("d" , "7891");
	t1.insert("m" , "dfxgdf");
	t1.print(t1.root);
    cout<<endl;
    t1.level();
	cout<<"===============================================================\n";
	t1.deletenode("d");

	t1.print(t1.root);
    t1.level();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

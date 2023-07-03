#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node* right;

    public:

    node(int data=0){
        this->data = data ;
        left = NULL;
        right = NULL;
    }

    ~node(){

    }
};

node* makeTree(node* root){
    int d;
    cout<<"Enter data :- ";
    cin>>d;
    if(d == -1){
        return NULL;
    }
    root = new node(d);

    cout<<"Enter data for left of "<<d<<endl;
    root->left = makeTree(root->left);

    cout<<"Enter data for right of "<<d<<endl;
    root->right = makeTree(root->right);

    return root;
}

void printByLevels(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); 

    while(!q.empty()){
        node* temp = q.front();
       
        
        if(temp == NULL){//old level is completely traversed
            cout<<endl;
            q.pop();
            if(!q.empty()){//queue is still left with some child nodes                     
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<"  ";
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelPrint(node* root){

    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL); 

    while(!q.empty()){
        node* temp = q.front();
       
        
        if(temp == NULL){//old level is completely traversed
            s.push(NULL);
            q.pop();
            if(!q.empty()){//queue is still left with some child nodes                     
                q.push(NULL);
            }
        }
        else{
            s.push(temp);
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

    while(!s.empty()){
        if(s.top() == NULL){
            cout<<endl;
        }else{
            cout<<s.top()->data<<"  ";
        }
        s.pop();
    }


}

void inOrder(node* root){
   stack<node*> st;
   node* curr = root;

   while(curr != NULL){
    st.push(curr);
    curr = curr->left;
   }
   if(!st.empty()) {
    node* temp = st.top();
    st.pop();
    cout<<temp->data<<" ";
    curr = temp->right;
   }
}

void makeByLevelOrder(node* &root){

    int d , left , right;
    queue<node*> q;
    cout<<"Enter data for root:- ";
    cin>>d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter data for left of "<<temp->data<<":- ";
        cin>>left;
        if(left != -1){
            temp->left = new node(left);
            q.push(temp->left);
        }
        cout<<"Enter data for right of "<<temp->data<<":- ";
        cin>>right;
        if(right != -1){
            temp->right = new node(right);
            q.push(temp->right);
        }  
    }

}

int main(){ 

    vector<int> v = {1,2,3,4,5,6};
    v.reserve(v.size());
    for(int i:v){
        cout<<i<<"  ";
    }
    cout<<endl;
    node* root;
    makeByLevelOrder(root);
    cout<<endl;
    printByLevels(root);
    //inOrder(root);
}
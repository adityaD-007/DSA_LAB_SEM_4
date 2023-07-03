#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d=0){
        data =d;
        next = NULL;
    }
};
class stackLL{
    public:
    node* head;
    node* tail;
    int size =0;

    stackLL(){
        node* temp = new node();
        head =temp;
        tail = temp;
        

    }

    void push(int d){
        size++;
        if(size ==1){
            head->data = d;
            
            return ;
        }
        node* temp = new node(d);
        tail->next = temp;
        tail = temp;
        
    }

    void pop(){
        if(size==0){
            cout<<"Stack is already empty"<<endl;
            return ;}

        node* temp = head;
        if(temp->next == NULL){
            size =0;
            return;
        }
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next ;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void showStack(){
        if(size==0){
            cout<<"Stack is empty"<<endl;
            return ;
        }
        node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp-> next;
        }cout<<endl;
    }

};


int main(){

    stackLL st;
    st.push(15);
    st.push(20);
    st.push(25);
    st.showStack();
    st.pop();
    st.showStack();
    st.pop();
    st.pop();
    st.pop();
    st.showStack();
    return 0;
}
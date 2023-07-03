#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;

    node(int d=0){
        data =d;
        prev =NULL;  
        next = NULL;
    }
};


void print(node* start){

        while(start != NULL){
        cout<<start->data<<" ";
        start = start->next;
        }cout<<endl;

}

int mian(){

      

    return 0;
}
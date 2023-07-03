#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;

    public:

    node(int data=0){
        this->data = data ;
        next = NULL;
    }

    ~node(){    

    }
};

void insertAtHead(node* &start , int data){
        node* temp = new node(data);
        
        temp->next =  start;
        start = temp;

}

void insertAtTail(node* &end , int d){
    node* temp = new node(d);
    end->next = temp;
    end = temp;
}

void inserAtAny(node* &start ,int position , int d ){

    node* nodetoinsert = new node(d);
    node * strt = start;
    if(position==1){
        nodetoinsert ->next = start;
        start = nodetoinsert ;
        return;

    }
    
    position-=2;

    while(position--){
        strt = strt->next;
    }
    nodetoinsert ->next = strt->next;
    strt->next = nodetoinsert ;

}

void print(node* s){

        node* start = s;
        if(start == NULL){
            cout<<"Empty\n";
        }
        while(start != NULL){
        cout<<start->data<<" ";
        start = start->next;
        }cout<<endl;

}

void deleteByPos(node* &start , int pos){

    if(pos == 1){
        node *temp= start;
        start = start->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    node* prev = NULL;
    node* del =start;  // memory to free/delete
    pos--;
    while(pos--){
        prev = del;
        del =del->next;
    }
    prev->next = del->next;
    del->next = NULL;
    delete del;

}



node* Reverselist(node* head){
    if(head == NULL || head->next == NULL  ){return head;}
    node* curr = head;
    node* prev = NULL;

   while(curr->next != NULL){
        node* fwrd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwrd;
    }
}

node* Middle(node* head){
    if(head->next ==NULL ){return head;}
    node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        head=head->next;
    }
    return head;
}

void merge(node* small , node* big){
            if(small->next == NULL){
                small->next = big; 
                return;
            }
            node* Snxt = small->next;
            while(Snxt != NULL && big != NULL){

                if(big->data >= small->data && big->data < Snxt->data){
                    node* Bnxt = big->next;
                    small->next = big;
                    big->next = Snxt;
                    small = big;
                    big = Bnxt;  
                }else{
                    small = Snxt;
                    Snxt = Snxt->next;
                    }
                      
                }
            
            if(small != NULL){
                small->next = big;
            }
}

node* addTwoNumbers(node* l1, node* l2) {
    cout<<"starting\n";

        l1 = Reverselist(l1);
        l2 = Reverselist(l2);

        node* ans ;
        node* curr;
        int carry = 0;

        while( l1 != NULL && l2 != NULL){
            cout<<"in the loop :- ";
            print(ans);
            int a = l1->data + l2->data + carry;
            carry = a/10;
            a = a%10;
            
            node *temp = new node(a);
            if(ans == NULL){
                ans = temp;
                curr = temp;
            }else{
                curr->next = temp;
                curr = temp;
            }
            
            l1 = l1->next;
            l2 = l2->next;

        }

        while(l1 != NULL){
            cout<<"in the loop 2 :- ";
            print(ans);
            int a = l1->data + carry;
            carry = a/10;
            a = a%10;
            
            node *temp = new node(a);
            curr->next = temp;
            curr = temp;
            l1 = l1->next;
        }
         while(l2 != NULL){
            cout<<"in the loop 3 :- ";
            print(ans);
            int a = l2->data + carry;
            carry = a/10;
            a = a%10;
            node *temp = new node(a);
            curr->next = temp;
            curr = temp;
            l2 = l2->next;
        }

        return ans;
}

node* rotateRight(node* head, int k) {
        if(head == NULL || head->next == NULL){return head;}
        int len=1;
        node* lent = head;

        while(lent->next != NULL){
            len++;
            lent = lent->next;
        }
        lent->next = head;
        int a = len - k;
        if(a == 0){
            return head;
        }
        while(a<0){
            a = len+a;
        }
        node* temp = head;
        node* prev = NULL;
        for(int i=0;i<a;i++){
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        return temp;
        

    }

int main(){

    // node* n1=new node(1);
    // node* start = n1;
    // node* end = n1;
    // insertAtTail(end , 2);
    // insertAtTail( end,4);
    
    // print(start);

    // node* n2 = new node(1);
    // node* s2 = n2;
    // node* e2 =n2;

    // insertAtTail(e2 , 3);
    // insertAtTail(e2,4);
    // print(s2);
    // s2 = Reverselist(s2);
    // print(s2);
    // start = zipperlist(start ,s2);
    // print(start);
    // cout<<endl;


    // node* n1 = new node(3);
    // node* n2 = new node(4);
    // node* s1 = n1;
    // node* s2 = n2;
    // insertAtHead(s1 , 4);
    // insertAtHead(s1 , 2);
    // insertAtHead(s2 , 6);
    // insertAtHead(s2 , 5);
    // print(s1);
    // print(s2);

    // node* ans = addTwoNumbers(s1 , s2);
    // print (ans);

    // node* n1 = new node(2);
    // node* head = n1;
    // insertAtHead(head , 1);
    // insertAtHead(head , 0);
    // print(head);
    // node* n = rotateRight(head , 2);
    // print(n);

    
    return 0;
}
//============================================================================
// Name        : 21116A.cpp
// Author      : aditya darade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class slot{
	friend class hashc;
	string word , meaning;
	slot* next;
public:
	slot(string w="$" , string m= "$"){
		word = w;
		meaning = m;
		next = NULL;
	}
};

class hashc{
	slot* arr[37];
public:

	hashc(){
		for(int i =0; i<37; i++){
			arr[i] = NULL;
		}
	}

	int hashfun(string key){
		int ind=0;
		for(int i = key.length() ; i>=0 ; i--){
			ind += key[i]+i;
		}
		ind = ind%37;
		return ind;
	}

	void insert(string key , string val){
		int i = hashfun(key);

		if(arr[i] == NULL){
			arr[i] = new slot(key , val);
		}else{
			slot* temp = arr[i] ;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new slot(key , val);
		}
	}

	void display(){

		for(int i=0 ; i<37 ; i++){
			if(arr[i] != NULL){
				slot* temp = arr[i];
				while( temp != NULL){
					cout<<temp->word <<"  -  "<<temp->meaning<<endl;
					temp = temp->next;
				}
			}
		}
	}

	void search(string key){
		int i = hashfun(key);
		if(arr[i] == NULL){
			cout<<" Key doesn't exist\n";
			return ;
		}
		slot* temp = arr[i];
		while(temp != NULL && temp->word != key){
			temp = temp->next;
		}
		if(temp){
			cout<<temp->word <<"  -  "<<temp->meaning<<endl;
		}else{
			cout<<"Not found\n";
		}
	}

	void deleteword(string key){
		int i = hashfun(key);

		if(arr[i] == NULL){
			cout<<" Key doesn't exist\n";
			return ;
		}
		slot* prev = NULL;
		slot* curr = arr[i];

		while(curr != NULL && curr->word != key){
			prev = curr;
			curr = curr->next;
		}
		if(curr == NULL){
			cout<<" Key doesn't exist\n";
			return ;
		}
		
		if(prev == NULL){
			arr[i] = curr->next;

		}else{
			prev->next = curr->next;
		}

		delete curr;

	}
};

int main() {
	hashc h1;

	cout<<"--------------------Menu---------------------\n";
	cout<<"1)Insert Word & Meaning\n2)Search a Word\n3)Display Whole Dictionary\n4)Delete a word\n\n";
	int x;
	string key , val;
	while(1){
		cout<<"\nEnter your choice :- ";
		cin>>x;
		cout<<"==========================================\n";
		if(x==1){
			cout<<"Enter word & meaning :- ";
			cin>>key>>val;
			h1.insert(key , val);
		}else if(x==2){
			cout<<"Enter word :- ";
			cin>>key;
			h1.search(key);
		}else if(x==3){
			h1.display();
		}else if(x==4){
			cout<<"Enter word :- ";
			cin>>key;
			h1.deleteword(key);
		}else{
			break;
		}
		cout<<"==========================================\n";
	}
	return 0;
}
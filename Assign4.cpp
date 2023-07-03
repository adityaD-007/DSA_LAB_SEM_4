//============================================================================
// Name        : hashing.cpp
// Author      : Aditya Darade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<bits/stdc++.h>

class entry{
	friend class hashmap;
	string number,name;

public:
	entry(string no="-1" , string n="$"){
		number = no;
		name = n;
	}
	string getname(){
		return name;
	}
};

class hashmap{
	entry* ht;
	int size;
public:
	hashmap(int n=17){
		ht = new entry[n];
		size = n;
	}

	int hash(string key){

		int sum=0;
		for(int i=9 ; i>=5;i--){
			int n = key[i]-'0';
			sum += n*i;
		}

		return sum%size;
	}

	void insert(string key , string val){

		int ind = hash(key);

		int i = ind;
		while(ht[i].number != "-1"){
			i++;
			if(i==size) i=0;
			if(i== ind) {
				cout<<"Table Full\n";
				return;
			}
		}
		ht[i].number = key;
		ht[i].name = val;
		
	}

	void insertB(string key , string val){

		int ind = hash(key);


		if(ht[ind].number == "-1" ){
			ht[ind].number = key;
			ht[ind].name = val;
			return;
		}
		if(hash(ht[ind].number) != ind){
			string newno = ht[ind].number;
			string newname = ht[ind].name;
			ht[ind].number = key;
			ht[ind].name = val;
			insert(newno , newname); 
		}
		int i = ind;
		while(ht[i].number != "-1"){
			i++;
			if(i==size) i=0;
            if(i== ind) {
                cout<<"Table Full\n";
                return;
            }
		}
		ht[i].number = key;
		ht[i].name = val;

	}

	int search(string key){

		int ind = hash(key);

		int i = ind;
		do{
			if(ht[i].number == key){
                //cout<<"data is :- "<<ht[i].name<<endl;
				return i;
			}
			i++;
			if(i == size) i = 0;
		}while(i != ind);

		return -1;
		
	}
	void show(int i){
		if(i==-1){
			cout<<"not found\n";
			return;
		}
		cout<<"data is :- "<<ht[i].name<<endl;
	}

	void delete_(string key)
	{
		int ind = hash(key);

		if(ht[ind].number == key){
			int i = (ind+1)%size;
			while(hash(ht[i].number) != ind){

				if( i == ind){
					ht[i].number = "-1";
					return;
				}
				i = (i+1)%size;
			}
			ht[ind].number = ht[i].number;
			ht[ind].name = ht[i].name;
			ht[i].number = "-1";
		}else{
			int i = ind;
			do{
				if(ht[i].number == key){
					ht[i].number = "-1";
					return;
				}
				i++;
				if(i == size) i = 0;
			}while(i != ind);
		}
	}

	void display(){

		for( int i=0;i<size ;i++){
			if(ht[i].number != "-1"){
				cout<<ht[i].name<<" - "<<ht[i].number<<endl;
			}
		}
	}

	void update(string key , string nval){
		int ind = search(key);

		ht[ind].name = nval;
	}
};
int main() {

	hashmap h1(7);

	h1.insertB("4586754687" , "aditya");
	h1.insertB("4586756787" , "parth");
	h1.insertB("4586754569" , "ved");
	h1.insertB("4586754636" , "adi");
	h1.display();
	cout<<"Enter number to be search :- ";
	string s;
	cin>>s;

	int i = h1.search(s);
	h1.show(i);
	cout<<"================================================";
	h1.update("4586754687" , "hfiowehgoierwj");
	h1.display();
	cout<<"================================================";
	h1.delete_("4586754569");
	h1.display();


	cout << "!!!Hello World!!!" << endl;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    map<string ,int> m;

    for(int i=0;i<2;i++){
        cout<<"Enter name and population:- ";
        string s;
        int n;
        cin>>s>>n;
        m.insert({s,n});
    }
    string s;
    cout<<"enter state name you wanna find population of :- ";
    cin>>s;
    map<string , int> :: iterator it = m.begin();
    it = m.find(s);
    if(it != m.end()){
        cout<<"Population of state " <<s<<"is :- "<<it->second<<endl<<endl;
    }else{
        cout<<"NOT FOUND !!"<<endl;
    }
    
}
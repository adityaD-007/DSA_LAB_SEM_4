#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class records{
    public:
    int roll;
    string name , tele , dob;
    
    records(int k){
        roll = k;
        name = tele = dob = "";
    }
    
    bool operator == (const records &obj){ 
        if(this->roll == obj.roll){
            return true;
        }
        return false;
    }
    records(){
        cout<<"\nEnter the info:-\nname\ndate of birth\ntelephone\nroll number\n\n";
        string n,d,t;
        int r;
        cin>>n>>d>>t;
        cin>>r;
        name = n;
        dob = d;
        tele = t;
        roll = r;
    }

    void display(){
        
        cout<<"Record :- \n";
        cout<<roll<<endl<<name<<endl;
        cout<<tele<<endl<<dob<<endl;
        cout<<"=====================================================\n";

    }
};

bool asending(records& obj1 , records& obj2){

    if(obj1.roll < obj2.roll){
        return true;
    }
    return false;
}


int main(){

    vector<records> v;
    int n ;
    cout<<"enter the number of records you wanna enter :- ";
    cin>>n;
    for(int i=0;i<n;i++){
        records r;
        v.push_back(r);
    }

    sort(v.begin(),v.end(),asending);
    cout<<"=====================================================\n";
    for(int i=0;i<n;i++){
        v[i].display();
    }
    int r;
    cout<<"Enter the roll number you want to find :- ";
    cin>>r;
    records key(r);

    vector<records> :: iterator it;
    it = find(v.begin(),v.end(),key);
    cout<<it->name<<endl;
}
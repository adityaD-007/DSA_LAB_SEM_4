#include <iostream>
using namespace std;



int main(){
cout<<"Enter"<<endl;
        int n ,m,k,x;
	    cin>>n>>m>>k>>x;
	    int year=1;
	    while((x)>=0){
	        
	        
	        
            if(year%k != 0){
                x = x - (n*k-1);
                year += k-1;
            }
            
            if(year%k==0){
	            x = x - m;
                if(x<=0){
                break; 
                }
                year++;
	        }
            
            
	        
	        
	    }
	    if(year%k==0){
	            cout<<"yes"<<endl;
	        }else{
	            cout<<"no"<<endl;
	    }


    return 0;
}
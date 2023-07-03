#include<iostream>
using namespace std;

class student{
protected:
    friend class college; // friend class can acess all the thing in this class even private
	static int count;
	string  name , address;
	char div;
    string number;
	string dob;
    int RN;

	public:
    
		student (){ //Default constructor
		    this->RN =0;        // setting default value to 0 	
		}
		student (int a){
            count++;  // static variable to keep count.
			cout<<"\nEnter name of student : ";
			cin>>this->name;
            cout<<"Enter roll number of student : ";
            cin>>this->RN;
			cout<<"\nEnter division of student : ";
			cin>>this->div;                                     // single char input de ...like 'a' , 'd' , 'z'
			cout<<"\nEnter address of student : ";
			cin>>this->address;                                      // address input detana space nko deu getline nahi use kela
			cout<<"\nEnter mobile number of student : ";;
			cin>>this->number;                                      // konta ch input detana space nko deu ....ok!!
			cout<<"\nEnter date of birth dd/mm/yyyy : ";
			cin>>this->dob;
		}

        inline void showCnt(){ 
            cout<<"Total number of student are :- "<<count<<endl; 
            /*
                inline function means ... it replaces function body at location of function call
                thats why it is good to use only for small(basic) functions
            */ 
        }

		void showinfo(){
            cout<<"Roll number "<<RN<<" Student's info :- \n";
            cout<<"Name          :- "<<this->name<<endl;
            cout<<"Division      :- "<<this->div<<endl;
            cout<<"Address       :- "<<this->address<<endl;
            cout<<"Phone number  :- "<<this->number<<endl;
            cout<<"Date of birth :- "<<this->dob<<endl;
            cout<<"================================================\n";
		}

        student(student &obj){ // just copying obj info to another obj(which called the function)
            this->RN = obj.RN;
            this->name = obj.name;
            this->address = obj.address;
            this->number = obj.number;
            this->dob = obj.dob;
            this->div = obj.div;
        }

        ~student(){
            //destructor
        }
};
int student :: count =1;


class college{
    student* arr;
    int total;
    public:

    college(int n){
        total = n;
        arr = new student[total]; // 'n' obj created dynamically
    }

    void set(){
        for(int i=0;i<total;i++){ 
            cout<<"\n                 Enter the data \n";
            arr[i]=student(i);
	    }
    }

    void get(){
        arr[0].showCnt();
        cout<<endl<<endl;
        for(int i=0;i<total;i++){ 
            arr[i].showinfo();
	    } 
    }

    ~college(){
        delete arr;
        //using delet keywords frees the dynamically allocated memory ....!
        // elements are alocated by using 'new' keyword thats why delelted by 'delete' keyword
    }

};

int main(){

	int n;
	cout<<"\nEnter number of student you want fill in details of :"<<endl;
	cin>>n;
    college c(n);
	c.set();
    cout<<"\n\n\n====================================================================\n====================================================================\n\n";
    c.get();
	return 0;
}
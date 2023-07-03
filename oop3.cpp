//============================================================================
// Name        : exam3.cpp
// Author      : adityathecoder
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class publication{
string title;
int price;
public:
publication(){
title = "";
price = 0;
}

int getPrice() const {
return price;
}

void setPrice(int price) {
try{
if(price > 5000 || price < 0){
    this->price = 0;
    throw "Price out of range";
}
this->price = price;
}catch(const char* message){
cout << "Exception caught!!" << message << endl;

title = "NULL";
}
}

const string& getTitle() const {
return title;
}

void setTitle(const string &title) {
this->title = title;
}


};
class book : public publication{
int page_count;
public:
book(){
page_count = 0;
}

int getPageCount() const {
return page_count;
}

void setPageCount(int pageCount) {
try{
if(pageCount > 500 || pageCount <= 0){
throw "Page_count out of index";
}
this->page_count = pageCount;
}catch(const int* count){
cout << "Exception caught!!" << count << endl;
count = 0;
}
}
};
class tape : public publication{
float play_time;
public:
tape(){
play_time = 0.0;
}

float getPlayTime() const {
return play_time;
}

void setPlayTime(float playTime) {
    try{
    if(play_time == 0 || play_time < 0){
    throw "Invalid playing time";
    }play_time = playTime;
    }catch(const int* count){
    cout << "Exception caught!!" << count << endl;
    count = 0;
    }
}


};
int main() {

//publication pub;
book b;
tape t;
cout << "1: Enter title of book\n2: Enter price of book\n3: Enter page_count of book\n4: Enter playing time of cassetts\n5: DISPLAY\n";
int flag = 0,n;
while(flag != 1){

cin >> n;
if(n == 1){
string title ,t;
cout << "Enter title : ";
cin>>title;
b.setTitle(title);
t = b.getTitle();
cout << "TITLE : " << t << endl;
}else if(n == 2){
int price,p;
cout << "Enter price : ";
cin >> price;
b.setPrice(price);
p = b.getPrice();
cout << "PRICE : " << p << endl;
}else if(n == 3){
int pg;
cout << "Enter page_count of book : ";
cin >> pg;
b.setPageCount(pg);
cout << "PAGECOUNT : " << b.getPageCount() << endl;
}else if(n == 4){
int pt;
cout << "Enter playing time of cassetts";
cin >> pt;
t.setPlayTime(pt);
cout << "PLAYING TIME : " << t.getPlayTime() << endl;
}
else{
 flag = 1;
}
}
return 0;
}
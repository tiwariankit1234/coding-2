#include<iostream >
#include<string.h>
using namespace std;
class String{
private:
char* ptr;
public:
String(const char* s){
string str=new char[strlen(s)+1];
strcpy(string,s);}
void display() const{
cout<<string<<endl;}	
void input(){
int x=strlen(string);
for(int i=0;i<x;i++){
if(str[i]>= 'a' && str[i]<= 'z'){
str[i]=str[i]-32;}}}};

int main(){
String myString("AbhaySoni");
cout<<"Original string :";
myString.display();
myString.input();
cout<<"new string :";
myString.display();}


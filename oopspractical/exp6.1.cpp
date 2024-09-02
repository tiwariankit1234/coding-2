#include<iostream >
using namespace std;
class Student{
public:
string name;                                                                                                       string gender;
int roll_no;
int marks;
int age;};
int main(){
Student S;
Student *ptr;
ptr=&S;
S.name="Abhay";
S.gender="Male";
S.roll_no=151;
S.marks=50;
S.age=20;
cout<<"Name:"<<ptr->name<<endl;
cout<<"Gender :"<<ptr->gender<<endl;
cout<<"Roll no. :"<<ptr->roll_no<<endl;
cout<<"Marks :"<<ptr->marks<<endl;
cout<<"Age :"<<ptr->age<<endl;}

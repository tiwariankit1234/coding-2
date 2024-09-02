#include<iostream>
using namespace std;

class Fraction{
    private:
    int num;
    int denom;
public:
Fraction(int num,int denom){
this->num=num;
this->denom=denom;
}

bool friend operator &&(Fraction &f1,Fraction &f2);
 
    
};


bool operator &&(Fraction &f1,Fraction &f2){
    if(f1.num==0)
    return false;
    else if(f2.num==0)
    return false;
    else
    return true;
}

int main(){
    Fraction f1(1,2),f2(0,3);
    if(f1 && f2){
        cout<<"1"<<endl;
    }
        else
        cout<<"0"<<endl;
        return 0;
    
}
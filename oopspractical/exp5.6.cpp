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

bool operator >(Fraction &f2){
    return(this->num)/(this->denom)>(f2.num/f2.denom);
}
    
};

int main(){
    Fraction f1(1,2),f2(1,3);
    if(f1>f2){
        cout<<"1"<<endl;
    }
        else
        cout<<"0"<<endl;
        return 0;
    
}
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

void multiply(Fraction &f2){
    num*=f2.num;
    denom*=f2.denom;
}
void show(){
    cout<<num<<"num"<<" "<<denom<<"denom"<<endl;
}
};

int main(){
        Fraction f1(2,3);
        Fraction f2(4,5);
        f1.multiply(f2);
        f1.show();
}
#include<iostream>
using namespace std;
class Fraction{
    public:
    int num;
    int denom;
    
    Fraction(int num,int denom){
        this->num=num;
        this->denom=denom;
    }
  void operator[](Fraction &other){
        this->num=(this->num)%denom;
        this->denom=this->denom;
       

    }
};
int main(){
   
     
    Fraction f1(12,5);
   
   f1[f1];
cout<<f1.num<<" "<<f1.denom<<endl;


    
}
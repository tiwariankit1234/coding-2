#include<iostream>
using namespace std;

class ABC;

class XYZ{
private:
    int x;
public:
    void setnumber(int num) {
        x=num;
    }
    friend void maximum(ABC,XYZ);
};

class ABC{
private:
    int y;
public:
    void setnumber(int num) {
        y=num;
    }
    friend void maximum(ABC,XYZ);
};

void maximum(ABC t1,XYZ t2){
    if(t1.y>t2.x)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
}

int main(){
    ABC a;
    a.setnumber(10);
    XYZ b;
    b.setnumber(9);
    maximum(a,b); // Corrected function call
    return 0;
}

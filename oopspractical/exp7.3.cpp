#include <iostream>
using namespace std;

class shape {
public:
    double x, y;

    void getData() {
        cout << "Enter 1st dimension: " << endl;
        cin >> x;
        cout << "Enter 2nd dimension: " << endl;
        cin >> y;
    }

     void displayArea() {
        cout << "Area: " << x * y << endl;
    }
};

class Triangle : public shape {
public:
    void displayArea()  {
        getData();
        cout << "Area: " << 0.5 * x * y << endl;
    }
};

int main(){
    shape* v;
    Triangle t;
    v=&t;
    v->getData();
  v->displayArea();




}
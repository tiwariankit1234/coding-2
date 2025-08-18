#include<iostream>
using namespace std;

class Foo {
     condition_variable cv;
    mutex m;
    int next=1;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        next=2;
      cv.notify_all();  
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line. 
        unique_lock lk(m);
        cv.wait(lk,[this](){return next==2;});
        printSecond();
        next=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.     
       unique_lock lk(m);
       cv.wait(lk,[this](){
        return next==3;
       });
       printThird();
       
    }
};
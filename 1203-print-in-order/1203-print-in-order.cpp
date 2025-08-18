class Foo {
    atomic_int flag=1;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag++;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line. 
        while(flag<=1);
        printSecond();
        flag++;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.     
        while(flag<=2);
        printThird();
       
    }
};
class CustomStack {
public:

int size;
int capacity;
vector<int>v;

    CustomStack(int maxSize) {
       size=0;
       capacity=maxSize;
       v.resize(maxSize);
    
        
    }
    
    
    void push(int x) {
        if(isFull())return ;
         size++;
         v[size-1]=x;
     
        return ;
    }
    
    int pop() {
        if(isEmpty())return -1;
        int x=v[size-1];
       
        v.pop_back();
         size--;
        return x;
    }

   bool isFull(){
    return size==capacity;
   }

   bool isEmpty(){
    return size==0;
   }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,size);i++){
        v[i]+=val;
        }
        return ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
class CustomStack {
public:
vector<int>v,incremented;
int size;
int capacity;


    CustomStack(int maxSize) {
       size=0;
       capacity=maxSize;
       v.resize(maxSize);
       incremented.resize(maxSize);
    }
    
    
    void push(int x) {
        if(isFull())return ;
         size++;
         v[size-1]=x;
     
        return ;
    }
    
    int pop() {
        if(size>=0){
        if(isEmpty())return -1;
        int x=v[size-1];
        int y=incremented[size-1];
        // cout<<y<<endl;
         if(size>=2){
        incremented[size-2]+=y;
         }

       
         v[size-1]=0;
        incremented[size-1]=0;
       size--;
     
        return x+y;
        }
        return -1;
    }
    

   bool isFull(){
    return size==capacity;
   }

   bool isEmpty(){
    return size==0;
   }
    
    void increment(int k, int val) {
        if(size>=1){
        int t=min(size,k);
        incremented[t-1]+=val;
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
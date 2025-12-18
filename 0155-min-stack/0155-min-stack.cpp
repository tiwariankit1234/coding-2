class MinStack {
public:
stack<int>st;
stack<int>minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
       if(minstack.empty() || minstack.top()>=val)
        minstack.push(val);
    }
    
    void pop() {
        if((int)st.top()==(int)minstack.top()){
            minstack.pop();
        }
        st.pop();
    }
    
    int top() {
        return (int)st.top();
    }
    
    int getMin() {
        return (int)minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
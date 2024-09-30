#include <vector>
#include <algorithm>  // For std::min
using namespace std;

class CustomStack {
public:
    int size;
    int capacity;
    vector<int> v;

    CustomStack(int maxSize) : size(0), capacity(maxSize), v() {
        // No need to resize; start with an empty vector
    }

    void push(int x) {
        if (isFull()) return;  // Check if stack is full
        v.push_back(x);  // Add element to the stack
        size++;  // Increment size
    }

    int pop() {
        if (isEmpty()) return -1;  // Return -1 if stack is empty
        int x = v.back();  // Get the top element
        v.pop_back();  // Remove the top element
        size--;  // Decrement size
        return x;  // Return the popped value
    }

    bool isFull() {
        return size == capacity;  // Check if stack is full
    }

    bool isEmpty() {
        return size == 0;  // Check if stack is empty
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, size); i++) {  // Increment only up to k or size
            v[i] += val;  // Increment each of the first k elements by val
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
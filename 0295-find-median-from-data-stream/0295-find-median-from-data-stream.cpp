class MedianFinder {
public:
priority_queue<int>maxq;
priority_queue<int,vector<int>,greater<int>>minq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxq.push(num);
        int x=maxq.top();
        maxq.pop();
        minq.push(x);
        if(minq.size()>maxq.size()){
            x=minq.top();
            minq.pop();
            maxq.push(x);
        }
    }
    
    double findMedian() {
        if(maxq.size()>minq.size()){
            return maxq.top();
        }
        else{
            return (maxq.top()+minq.top())/2.0;
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
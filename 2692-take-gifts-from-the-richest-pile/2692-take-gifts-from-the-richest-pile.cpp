class Solution {
public:
#define ll long long 

    long long pickGifts(vector<int>& gifts, int k) {
        ll n=gifts.size();
        priority_queue<ll,vector<ll>,less<ll>>pq;
        for(auto it:gifts){
            pq.push(it);
        }

        while( k){
           ll maxelement=pq.top();
            pq.pop();
            pq.push(sqrt(maxelement));
            k--;
        }
        ll sum=0;
        while(pq.size()>0){
           sum+=pq.top();
           pq.pop();
        }
        return sum;
    }
};
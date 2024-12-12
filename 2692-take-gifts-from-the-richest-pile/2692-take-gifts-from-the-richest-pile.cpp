class Solution {
public:
#define ll long long 

    long long pickGifts(vector<int>& gifts, int k) {
        ll n=gifts.size();
        priority_queue<ll,vector<ll>,less<ll>>pq;

        ll sum=0;
        for(auto it:gifts){
            pq.push(it);
            sum+=it;
        }

        while( k){
           ll maxelement=pq.top();
            pq.pop();
            sum-=maxelement;
            pq.push(sqrt(maxelement));
            sum+=sqrt(maxelement);
            k--;
        }
      
        return sum;
    }
};
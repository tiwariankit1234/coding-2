class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        long long sum=0;
        int z=k;

        while(z>=1){
         int x=pq.top();
           sum+=x;
            pq.pop();
            pq.push(ceil(x/3.0));
            
            
            
            z--;
            // cout<<k<<" "<<sum<<" "<<x/3<<" "<<endl;
        }
        return sum;

    }
};
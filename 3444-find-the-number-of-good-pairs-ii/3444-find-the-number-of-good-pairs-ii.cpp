#define ll long long 
class Solution {
public:
void getFactors(int n,vector<int>&factors) {
 
    
    // Iterate from 1 to sqrt(n)
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {  // If i is a factor
            factors.push_back(i);
            if (i != n / i)  // Avoid duplicate if n is a perfect square
                factors.push_back(n / i);
        }
    }
    
 // Sorting the factors
    return ;
}

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>allfactors;
        for(auto it:nums1){
            getFactors(it,allfactors);
        }
        unordered_map<int,int>mp;
        for(auto it:allfactors){
            mp[it]++;
        }
    ll ans=0;
        for(auto&it:nums2){
             it*=k;
             if(mp.find(it)!=mp.end())
                  ans+=mp[it];
        }
        return ans;
    }
};
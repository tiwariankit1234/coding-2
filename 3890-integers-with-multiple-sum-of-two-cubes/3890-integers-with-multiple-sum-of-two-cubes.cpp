class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        if(n<1729)return {};
        vector<int>temp,ans;
        // for(int i=1;i<1000;i++){
        //  int x=i*i*i;
        //  temp.push_back(x);
        // }
        int limit=cbrt(n);
        // sort(temp.begin(),temp.end());
            unordered_map<int,int>mp;
        for(int i=1;i<=limit;i++){
            for(int j=i;j<=limit;j++){
                int k=i*i*i+j*j*j;
                mp[k]++;
                
            }
        }
        // cout<<mp.size()<<endl;
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(auto it:mp){
            if(it.second>=2 and it.first<=n){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
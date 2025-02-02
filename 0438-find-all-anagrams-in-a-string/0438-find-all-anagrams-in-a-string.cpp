class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),k=p.size();
        if(n<k)return {};
        unordered_map<char,int>mp1,mp2;
        for(auto it:p){
            mp2[it]++;
        }
        vector<int>ans;
        int l=0,r=0;
        while(r<n){
            mp1[s[r]]++;
            if(r-l+1==k){
                if(mp2==mp1){
                    ans.push_back(l);
                }
                mp1[s[l]]--;
                if(mp1[s[l]]==0)mp1.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
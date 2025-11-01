class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)mp[s[i]]++;
        sort(s.begin(),s.end(),([&](char &a,char &b){
            if(mp[a]==mp[b])return a<b;
            return mp[a]>mp[b];
        }));
        return s;
    }
};
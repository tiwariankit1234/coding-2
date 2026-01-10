class Solution {
public:
unordered_map<char,vector<char>>mp;

void f(int idx,string s,string& digits,vector<string>&ans){
    if(s.size()==digits.size()){
        ans.push_back(s);
        return ;
    }
        auto temp=mp[digits[idx]];
        int n=temp.size();
        for(int i=0;i<n;i++){
         f(idx+1,s+temp[i],digits,ans);
        }
    return ;
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        mp['2']={'a','b','c'};
mp['3']={'d','e','f'};
mp['4']={'g','h','i'};
mp['5']={'j','k','l'};
mp['6']={'m','n','o'};
mp['7']={'p','q','r','s'};
mp['8']={'t','u','v'};
mp['9']={'w','x','y','z'};
        string s="";
        f(0,s,digits,ans);
        return ans;
    }
};
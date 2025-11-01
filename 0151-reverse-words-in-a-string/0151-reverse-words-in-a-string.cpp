class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string k;
        vector<string>ans;
        while(ss>>k){
           ans.push_back(k);
        }
        string temp="";
        int n=ans.size();
        temp+=ans[n-1];
        for(int i=n-2;i>=0;i--){
           temp+=" "+ans[i];
        }
        return temp;
    }
};
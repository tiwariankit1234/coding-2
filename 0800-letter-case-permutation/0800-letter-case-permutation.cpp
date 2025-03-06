class Solution {
public:

vector<string>ans;
string t="";
void f(int idx,string &s,string &t){
    if(idx==s.size()){
        ans.push_back(t);
        return ;
    }
    if(isalpha(s[idx])){
        t+=toupper(s[idx]);
        f(idx+1,s,t);
        t.pop_back();
        t+=tolower(s[idx]);
        f(idx+1,s,t);
        t.pop_back();
    }
    else{
        t+=s[idx];
        f(idx+1,s,t);
        t.pop_back();
    }
    return ;
}
    vector<string> letterCasePermutation(string s) {
     
         f(0,s,t);
         return ans;
    }
};
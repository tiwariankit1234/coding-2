class Solution {
public:
string f(string &s){
    int n=s.size();
    string t="";
    for(int i=0;i<(n-1);i++){
        t.push_back((s[i]+s[i+1])%10);
    }
    return t;
}
    bool hasSameDigits(string s) {
        int n=s.size();
        while(s.size()>2){
            s=f(s);
        }
        if(s[0]!=s[1])return false;
        else 
            return true;
    }
};
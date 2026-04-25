class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
       bool flag=false;
       if(s[0]!=(x+'0'))flag=true;
       bool present=false;
       for(int i=1;i<s.size();i++){
        if(s[i]==(x+'0'))present=true;
       }
       return flag&present;
     
    }
};
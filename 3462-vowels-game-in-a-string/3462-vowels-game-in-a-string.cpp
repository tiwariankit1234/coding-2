class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size();
        int vowelcount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' ||s[i]=='e'||s[i]=='i' ||s[i]=='o'||s[i]=='u')vowelcount++;
        }
        if(vowelcount==0)return false;
        return true;
    }
};
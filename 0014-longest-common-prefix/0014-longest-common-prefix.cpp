class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[n-1];
        string commonstring="";
        for(int i=0;i<(min(s1.size(),s2.size()));i++){
            if(s1[i]!=s2[i])
            break;
            else{
                commonstring+=s1[i];
            }
        }

        return commonstring;
    }
};
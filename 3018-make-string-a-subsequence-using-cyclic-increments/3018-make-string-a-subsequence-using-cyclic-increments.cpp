class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int i=0,j=0;
        int n1=s1.size(),n2=s2.size();

        while(i<n1 and j<n2){
            if(s1[i]==s2[j] || ((s1[i]-'a'+1)%26)==(s2[j]-'a')){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return (j==n2);
    }
};
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int i=0;
        string newstring="";
        while(i<n){
         if(i>=2 and s[i]==s[i-1]and s[i-1]==s[i-2]){
            i++;
         }
         else{
            newstring+=s[i];
            i++;
         }
     
        }
        return newstring;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        int j=0;
        while(j<s.size()){
           if(s[j]==s[j+1]){
            s.erase(j,2);
            if(j>0)j--;
           }
           else{
            j++;
           }
        }
        return s;
    }
};
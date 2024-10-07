class Solution {
public:
    int minLength(string s) {
         int n=s.size();
         int i=0,j=1;

         while(j<n){
            if((i>=0) and ((s[i]=='A' and s[j]=='B') || (s[i]=='C' and s[j]=='D'))){
                i--;
             
            }
            else{
                i++;
                s[i]=s[j];
               
            }
            j++;
         }
         return i+1;
    }
};
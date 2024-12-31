#define ll long long 
class Solution {
public:
    long long numberOfWays(string s) {
     ll totalzero=0,totalone=0;
     ll n=s.size();
     // for 010 count zero
     ll leftzero=0,leftone=0,count=0;
     for(int i=0;i<n;i++){
        if(s[i]=='0'){
            totalzero++;
        }
        else{
            totalone++;
        }
     }
     for(int i=0;i<n;i++){
       if(s[i]=='1'){
         count+=leftzero*(totalzero-leftzero);
       }
      else{
        leftzero++;
      }
     }
 //101
      for(int i=0;i<n;i++){
       if(s[i]=='0'){
         count+=leftone*(totalone-leftone);
       }
      else{
        leftone++;
      }
     }
     return count;
    }
};
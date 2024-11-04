class Solution {
public:
    string compressedString(string s) {
        int n=s.size();
        int count=1;
          if(n==1){
            return to_string(1)+s[0];
          }
          string ans="";
          for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans.push_back(count+'0');
                ans.push_back(s[i-1]);
                count=1;
                 }
                 else{
                   
                    if(count==9){
                        ans.push_back(count+'0');
                        ans.push_back(s[i-1]);
                         count=1;
                    }
                    else{
                     count++;
                    }
                 }
          }
          ans.push_back(count+'0');
          ans.push_back(s[n-1]);
          return ans;
    }

};
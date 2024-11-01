class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[1002][1002]{false};
     
       pair<int,int>ans;
        for(int i=0;i<n;i++){
            
                dp[i][i]=true;
                if(i<n-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=true;
                    ans={i,i+1};
                  
                }
                else{
                    dp[i][i+1]=false;
                }
            }
            
        } 

      

            // now we fill the dp with 1 and 2 length 
            for(int diff=2;diff<n;diff++){
                for(int i=0;i<n-diff;i++){
                    int j=i+diff;
                    if(s[i]==s[j] and dp[i+1][j-1]){
                        dp[i][j]=true;
                        ans={i,j};
                    }
                }
            }
        
        int i=ans.first;
        int j=ans.second;
        return s.substr(i,j-i+1);

    }
};
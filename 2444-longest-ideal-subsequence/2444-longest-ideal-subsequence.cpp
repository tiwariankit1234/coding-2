class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> arr(26, 0);
        int maxi = -1;
        for (int i = 0; i < n; i++) {
              int temp=0;
            for (int j = 0; j < 26; j++) {
              
                if (abs(s[i] - (j + 'a')) <= k) {
                    // cout<<i<<" "<<j<<" "<<endl;
                  temp=max(temp,arr[j]);
                }
                
            }
            arr[s[i]-'a']=temp+1;
             maxi=max(maxi,temp+1);
          
        }
       
        return maxi;
    }
};
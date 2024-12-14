class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
         }
         );

        int n=pairs.size();
        int length=1;
        int maxend=pairs[0][1];

        for(int i=1;i<n;i++){
           if(pairs[i][0]>maxend){
             maxend=pairs[i][1];
             length++;
           }
           else{
            maxend=min(pairs[i][1],maxend);
           }

        }
        return length;
    }
};
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>ans(105,0);
       int start=1000,end=-1;
        for(auto it:nums){
            int first=it[0];
            int second=it[1];
            start=min(first,start);
            end=max(end,second);
           ans[first]++;
           ans[second+1]--;   
        }

        for(int i=start;i<=end;i++){
            ans[i]+=ans[i-1];
        }
        int count=0;
         for(int i=start;i<=end;i++){
            if(ans[i]>0)
            count++;
         }
         return count;

        
       
    }
};
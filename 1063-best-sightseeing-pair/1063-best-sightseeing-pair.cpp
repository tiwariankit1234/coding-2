class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>copy=values;
       
        // for(auto it:values)
        // cout<<it<<" ";

        cout<<endl;
        vector<int>maxposition(n,0);
        int maxpost=values[n-1]-(n-1);
        for(int i=n-2;i>=0;i--){
           
            maxposition[i]=maxpost;
             maxpost=max(values[i]-i,maxpost);
        }
        // for(auto it:maxposition)
        // cout<<it<<" ";

        cout<<endl;
        int ans=0;
        for(int i=0;i<(n-1);i++){
            int currentvalue=(values[i]+i+maxposition[i]);
            ans=max(ans,currentvalue);
        }
        return ans;
    }
};
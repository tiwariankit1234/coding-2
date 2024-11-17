class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& query) {
        int n=nums.size();
        vector<int>linemapping(n+2,0),prefixarray(n,0);

        for(int i=0;i<query.size();i++){
            linemapping[query[i][0]]++;
            linemapping[query[i][1]+1]--;
        }
        prefixarray[0]=linemapping[0];

        // for(auto it:linemapping)cout<<it<<" ";

        cout<<endl;

       

        cout<<endl;
         
        //  cout<<prefixarray[0]<<endl;

        for(int i=1;i<n;i++){
          prefixarray[i]=prefixarray[i-1]+linemapping[i];
        }

        //  for(auto it:prefixarray)cout<<it<<" ";
         
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
               if(prefixarray[i]<nums[i])return false;
            }
        }

        return true;

       
        
    }
};
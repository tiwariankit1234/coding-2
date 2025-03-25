class Solution {
public:
    int countDays(int days, vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        map<int,int>mp;
        for(auto it:arr){
        mp[it[0]]++;
        mp[it[1]+1]--;
        }
        int count=0,sum=0;
        vector<int>ans;
        int previousday=1,start=0;
        for(auto it:mp){
         
            if(sum==0){
              count+=it.first-previousday;
            } 
             sum+=it.second;
              previousday=it.first;
          
        }
           previousday=previousday-1;
        if(previousday<=days){
            count+=days-previousday;
        }
       
        return count;
        
    }
};
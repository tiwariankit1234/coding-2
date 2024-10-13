class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        int i=0,j=k-1;
        
        while(j<n){

            map<int,int>mp;
            for(int a=i;a<=j;a++){
                mp[nums[a]]++;
            }

            priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>pq;
              
              for(auto it:mp){
                pq.push({it.second,it.first});
              }

           
             int sum=0;

             if(pq.size()<x){
               while(pq.size()<x and pq.size()>0){
                 sum+=(pq.top().second)*(pq.top().first);
                 pq.pop();
               }
             } 

             else {

                 int k=x;

             while(k>0){
              sum+=pq.top().second*(pq.top().first);
              pq.pop();
              k--;
             }
        }   
             ans.push_back(sum);

             i++;
             j++;
        }
        return ans;
    }
};
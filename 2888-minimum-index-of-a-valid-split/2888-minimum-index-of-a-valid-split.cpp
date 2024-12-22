class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int dominant=0;
        int secondfrequency=0;
        for(auto it:mp){
        if(it.second>=secondfrequency){
            dominant=it.first;
            secondfrequency=it.second;
        }
    }
       cout<<dominant<<endl;
    int j=0;
    int freq=0;
       for(int j=0;j<n;j++){
         if(nums[j]==dominant){
            // check it can form dominant;
             freq++;
             secondfrequency--;
             if((freq*2)>(j+1) and (secondfrequency*2)>(n-j-1)){
                 return j;
             }
         }
       }

       return -1;


    }
};
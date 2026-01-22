class Solution {
public:
bool check(vector<int>nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1])return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        if(check(nums))return 0;
        int count=0;
        while(!check(nums)){
           int minsum=INT_MAX,newidx=-1;
            for(int i=0;i<(nums.size()-1);i++){
                int sum=nums[i]+nums[i+1];
                if(sum<minsum){
                    minsum=sum;
                    newidx=i;
                }
            }
           
            vector<int>temp;
            
            for(int i=0;i<=newidx-1;i++){
                temp.push_back(nums[i]);
            }
            temp.push_back(minsum);
            for(int i=newidx+2;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            //  cout<<count<<endl;
            // for(auto it:temp){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            nums=temp;
            count++;
        }
        return count;
    }
};
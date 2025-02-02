class Solution {
public:
bool isSorted(vector<int>&temp){
    int n=temp.size();
    //    for(auto it:temp)
    //     cout<<it<<" ";
    for(int i=0;i<(n-1);i++){
      
        if(temp[i]>temp[i+1]){
            // cout<<temp[i]<<endl;
            return false;
        }
    }
    return true;
}
    bool check(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=0;i<(n-1);i++){
            if(nums[i]>nums[i+1]){
                index=i;
            }
        }
        vector<int>temp;
        for(int i=index+1;i<n;i++){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<=index;i++){
            temp.push_back(nums[i]);
        }
        // for(auto it:temp)
        // // cout<<it<<" ";
        // cout<<endl;
        return isSorted(temp);
        
    }
};
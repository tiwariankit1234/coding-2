class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int k=0;
        vector<int>ans;
        set<int>st1,st2,st3;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot)st1.insert(i);
            else if(nums[i]==pivot)st2.insert(i);
            else
            st3.insert(i);
        }
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==pivot)st2.insert(i);
        // }
        // for(int i=0;i<nums.size();i++){

        // }
        for(auto it:st1){
            ans.push_back(nums[it]);
        }
        for(auto it:st2)ans.push_back(nums[it]);
        for(auto it:st3)ans.push_back(nums[it]);
        return ans;
    }
};
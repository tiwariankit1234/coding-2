class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int count=0;
        for(int x:nums1){
            if(x&1)count++;
        }
        if(count==n||count==0)return true;
        vector<int>temp;
        for(auto it:nums1){
            if(it&1)temp.push_back(it);
        }
        sort(temp.begin(),temp.end());
        for(auto it:nums1){
            if(it%2==0){
                if(it-temp[0]<1)return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();

        int prefixmod=0,result=0;

        vector<int>modgroups(k);
        modgroups[0]=1;

        for(int num:nums){
            prefixmod=(prefixmod+num%k+k)%k;

            result+=modgroups[prefixmod];
            modgroups[prefixmod]++;
        }
        return result;
    }
};
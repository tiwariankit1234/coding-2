class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string s="";
        for(int i=0;i<n;i++){
            string t=nums[i];
            s=s+char(((t[(int)s.size()]-'0')^1)+'0');
        }
        return s;
    }
};
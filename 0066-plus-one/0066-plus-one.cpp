class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n=nums.size(),carry=0;
        vector<int>temp;
       
        if(nums[n-1]>=9){
            carry=1;
            temp.push_back(0);
        }
        else{
            carry=0;
            temp.push_back(nums[n-1]+1);
        }

        for(int i=n-2;i>=0;i--){
          int x=nums[i]+carry;
          if(x>9){
            carry=1;
            temp.push_back(0);
          }
          else{
            nums[i]=nums[i]+carry;
            temp.push_back(nums[i]);
            carry=0;
          }
        }
        if(carry==1)temp.push_back(1);
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
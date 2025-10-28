class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int major1=-1,major2=-1,count1=0,count2=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==major1){
                count1++;
            }
            else if(nums[i]==major2){
                count2++;
            }
            else if(count1==0){
                major1=nums[i];
                count1++;
            }
            else if(count2==0){
                major2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int freq1=0,freq2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==major1){
                freq1++;
            }
            else if(nums[i]==major2){
                freq2++;
            }
        }
        if(freq1>(n/3)){
          ans.push_back(major1);
        }
        if(freq2>(n/3)){
            ans.push_back(major2);
        }
        return ans;
    }
};
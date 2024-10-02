class Solution {
public:

 void f(int start,vector<int>&temp,vector<vector<int>>&ans,vector<int>&num){
    int n=num.size();
    if(start==n-1){
        temp.push_back(num[start]);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
       
       
      
      for(int idx=start;idx<n;idx++){
        swap(num[start],num[idx]);
        temp.push_back(num[start]);
        f(start+1,temp,ans,num);
        temp.pop_back();
        swap(num[idx],num[start]);
      }
 }


    vector<vector<int>> permute(vector<int>& nums) {
           vector<vector<int>>ans;
           vector<int>temp;
            f(0,temp,ans,nums);
            return ans;
    }
};
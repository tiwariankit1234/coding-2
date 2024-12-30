class Solution {
public:
int n;

vector<vector<int>>ans;
void f(vector<int>& candidates,int target,int idx,vector<int>&temp){
    if(idx==n){
        if(target<0)
        return ;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        return ;
    }
    // cout<<target<<endl;
    if(candidates[idx]<=target){
      temp.push_back(candidates[idx]);
    //  int t=target-candidates[idx];
    f(candidates,target-candidates[idx],idx,temp);
    temp.pop_back();
    }
    f(candidates,target,idx+1,temp);
    return ;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        n=candidates.size();
        vector<int>temp;
        f(candidates,target,0,temp);
        return ans;
    }
};
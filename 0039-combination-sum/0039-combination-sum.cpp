class Solution {
public:
int n;
// Every time you have N choice (since you can use number repeatedly), and you can choose at most target times (actually it's smaller than target), so we can assume the worst-case time complexity is O(N^target).
vector<vector<int>>ans;
void f(vector<int>& candidates,int target,int idx,vector<int>&temp){
       
       if(target<0)return ;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
    
    // cout<<target<<endl;
    // if(candidates[idx]<=target){
    //   temp.push_back(candidates[idx]);
    // //  int t=target-candidates[idx];
    // f(candidates,target-candidates[idx],idx,temp);
    // temp.pop_back();
    // }
    // f(candidates,target,idx+1,temp);
    for(int i=idx;i<n;i++){
       temp.push_back(candidates[i]);
        f(candidates,target-candidates[i],i,temp);
        temp.pop_back();
    }
    return ;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        n=candidates.size();
        vector<int>temp;
        f(candidates,target,0,temp);
        return ans;
    }
};
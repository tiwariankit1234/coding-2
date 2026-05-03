class Solution {
public:
    void f(int i, int n, vector<int>& ans, vector<vector<int>>& temp) {
        if (i == n) {
            temp.push_back(ans);
            return;
        };
        ans.push_back(i);
        f(i + 1, n, ans, temp);
        ans.pop_back();
        f(i + 1, n, ans, temp);
        return;
    }
    void dfs(int node,vector<int>&it,unordered_set<int>&visited1,unordered_set<int>&visited2,vector<vector<int>>&adj){

        visited2.insert(node);
        
        for(auto x:adj[node]){
            if(visited1.find(x)!=visited1.end() and visited2.find(x)==visited2.end()){
                dfs(x,it,visited1,visited2,adj);
            }
        }
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> temp;
        vector<int> ans;
        f(0, n, ans, temp);
        cout<<5<<endl;
       
         vector<vector<int>>adj(nums.size());
         for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
         }
        int count = 0;
        for (auto it : temp) {
            if(it.empty())continue;
            unordered_set<int>visited1;

            int sum=0;
            for(auto k:it){
                sum+=nums[k];
                visited1.insert(k);
            }
            unordered_set<int>visited2;
            dfs(it[0],it,visited1,visited2,adj);
             if(visited1==visited2 and sum%2==0)count++;
            
        }
        return count;
    }
};
class Solution {
public:
    int dp[50005];
    
    // Recursive function to maximize profit
    int f(int idx, vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        
        // Base case: if we've processed all jobs, return 0
        if (idx == n) {
            return 0;
        }
        
        // If the result for this subproblem has already been computed, return it
        if (dp[idx] != -1) {
            return dp[idx];
        }

        // Option 1: Don't take the current job (skip it)
        int notake = f(idx + 1, startTime, endTime, profit);
        
        // Option 2: Take the current job, if it doesn't overlap with the previous one
        int take = 0;
 
            take = profit[idx];

            auto lower1=lower_bound(startTime.begin()+idx,startTime.end(),endTime[idx]);
               int nextidx=lower1-startTime.begin();
            //    cout<<idx<<endl;
                take+=f(nextidx,startTime,endTime,profit);
        
        
        // Store the maximum profit of taking or not taking the current job
        return dp[idx] = max(take, notake);
    }

    // Main function that starts the recursion
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array to -1
        int n=profit.size();
        vector<tuple<int,int,int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());

         for (int i = 0; i < n; i++) {
            startTime[i] = get<0>(jobs[i]);
           endTime[i] = get<1>(jobs[i]);
            profit[i] = get<2>(jobs[i]);
        }
     
        
        // Start recursion from the first job, with no previous job selected (endidx = -1)
        return f(0,startTime,endTime,profit);
    }
};

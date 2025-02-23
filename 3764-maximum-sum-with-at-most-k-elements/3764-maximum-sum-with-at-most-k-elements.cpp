class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            // Flatten the grid into a list of (value, row) pairs
            vector<pair<int, int>> arr;
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[i].size(); j++){
                    arr.push_back({grid[i][j], i});
                }
            }
            
            // sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            //     return a.first > b.first;
            // });
            sort(arr.begin(),arr.end(),[](const pair<int,int>&a,const pair<int,int>&b){
                return a.first>b.first;
            });
            
            // Track selected elements per row and calculate the sum
            vector<int> count(grid.size(), 0); // Tracks elements selected from each row
            long long sum = 0;
            int selected = 0;
            
            for(const auto& it:arr){
              auto [value,row]=it;
                
                // If row limit is not exceeded and total selected < k, add to sum
                if(count[row] < limits[row] && selected < k) {
                    sum += value;
                    count[row]++;
                    selected++;
                }
                
                // Stop if k elements are selected
                if(selected == k) break;
            }
            
            return sum;
        }
    };
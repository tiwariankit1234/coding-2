class Solution {
public:
    int largestCombination(vector<int>& nums) {
        vector<int>ans(32,0);
        int count=0,value=0;
        for(int i=0;i<24;i++){
        for(int num:nums){
            //check if the i-th bit is set
            if((num&(1<<i))!=0) 
            ans[i]++;
        }

        }
       
        return *max_element(ans.begin(),ans.end());
    }
};





// #include <vector>
// #include <map>

// class Solution {
// public:
//     std::map<std::pair<int, int>, int> memo;

//     int f(const std::vector<int>& num, int idx, int previousand) {
//         if (previousand == 0) return 0;  // If AND becomes zero, return 0
//         if (idx == num.size()) return 0; // Reached end of array

//         // Check if result is already computed
//         if (memo.find({idx, previousand}) != memo.end()) {
//             return memo[{idx, previousand}];
//         }

//         // Option to pick the current element
//         int currentand = previousand & num[idx];
//         int pick=0;
//         if(currentand>0)
//          pick = 1 + f(num, idx + 1, currentand);

//         // Option to skip the current element
//         int nonpick = f(num, idx + 1, previousand);

//         // Store and return the maximum of the two options
//         return memo[{idx, previousand}] = std::max(pick, nonpick);
//     }

//     int largestCombination(std::vector<int>& num) {
//         // Set `previousand` to a high value (all bits set to 1)
//         int all_ones = ~0;
//         return f(num, 0, all_ones);
//     }
// };

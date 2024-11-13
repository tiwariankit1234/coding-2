#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : nums) {
            // Check how many previous elements make a sum < target with the current num
            for (auto& [key, value] : freq) {
                if (key + num < target) {
                    count += value;  // Add all occurrences of 'key' that satisfy the condition
                }
            }
            // Add the current number to the map
            freq[num]++;
        }
        
        return count;
    }
};

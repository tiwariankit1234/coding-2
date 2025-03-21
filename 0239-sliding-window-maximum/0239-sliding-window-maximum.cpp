#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution{
    public:


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    map<int, int> window; // Maps value -> frequency (ordered by key)
    
    // Process the first k elements
    for (int i = 0; i < k; i++) {
        window[nums[i]]++;
    }
    
    // Add the maximum of the first window to result
    result.push_back(window.rbegin()->first); // Get the largest key
    
    // Process the remaining elements
    for (int i = k; i < nums.size(); i++) {
        // Remove the leftmost element from the window
        int leftElement = nums[i - k];
        window[leftElement]--;
        if (window[leftElement] == 0) {
            window.erase(leftElement);
        }
        
        // Add the current element to the window
        window[nums[i]]++;
        
        // Add the maximum of the current window to result
        result.push_back(window.rbegin()->first);
    }
    
    return result;
}

};


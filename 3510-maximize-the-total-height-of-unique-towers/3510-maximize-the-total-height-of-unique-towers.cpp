#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(), maximumHeight.rend()); // Sort in descending order
        ll n = maximumHeight.size();
        
        ll previousHeight = maximumHeight[0]; // Start with the tallest tower
        ll maxHeight = previousHeight; // Initialize maxHeight with the tallest tower

        for (ll i = 1; i < n; i++) {
            if (maximumHeight[i] >= previousHeight) {
                previousHeight = previousHeight - 1; // Decrease height for uniqueness
            } else {
                previousHeight = maximumHeight[i]; // Assign current height
            }

            // If the assigned height goes below or equal to zero, return -1
            if (previousHeight <= 0) {
                return -1;
            }

            maxHeight += previousHeight; // Add assigned height to total
        }

        return maxHeight; // Return the total maximum height sum
    }
};
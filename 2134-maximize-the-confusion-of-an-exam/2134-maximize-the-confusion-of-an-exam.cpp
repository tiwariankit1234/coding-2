#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canMake(string &s, int k, int length, char ch) {
        int left = 0, right = 0, count = 0, n = s.size();

        while (right < n) {
            if (s[right] != ch) count++;  // Count non-matching characters
            
            while (count > k) {  // If more than k flips are required, shrink window
                if (s[left] != ch) count--;
                left++;
            }

            if (right - left + 1 >= length) return true;  // Valid segment found
            right++;
        }
        
        return false;  // No valid segment found
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 1, r = answerKey.size(), ans = 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            
            // Check if we can create a segment of length `mid` using at most `k` flips
            if (canMake(answerKey, k, mid, 'T') || canMake(answerKey, k, mid, 'F')) {
                ans = mid;  // Possible, increase search space
                l = mid + 1;
            } else {
                r = mid - 1;  // Not possible, decrease search space
            }
        }

        return ans;
    }
};

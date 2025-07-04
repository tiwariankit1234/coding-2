#include <vector>
#include <iostream>

class Solution {
public:
    // Recursive function to find the character at position k
    char findCharRecursive(int idx, long long k, const std::vector<int>& operations, char baseChar) {
        if (idx < 0) {
            return baseChar;
        }

        if (idx >= 63) {
            return findCharRecursive(idx - 1, k, operations, baseChar);
        }

        long long mid = 1LL << idx;

        if (k < mid) {
            return findCharRecursive(idx - 1, k, operations, baseChar);
        } else {
            // It came from the second half
            long long newK = k - mid;
            char sourceChar = findCharRecursive(idx - 1, newK, operations, baseChar);

            if (operations[idx] == 0) {
                return sourceChar;
            } else {
                // Increment character, wrap 'z' to 'a'
                return (sourceChar - 'a' + 1) % 26 + 'a';
            }
        }
    }

    char kthCharacter(long long k, std::vector<int>& operations) {
        return findCharRecursive(operations.size() - 1, k - 1, operations, 'a');
    }
};

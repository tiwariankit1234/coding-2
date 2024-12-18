#define ll long long 

class Solution {
public:
    map<int, map<int, int>> mp; // Nested map to store digit frequencies for keys

    void f(int num) {
        string s = to_string(num);
        int k = 0; // Variable to construct a unique key
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            mp[k][s[i] - '0']++; // Increment the count for the digit in the map
            k++; // Update the key (modify this as per your logic)
        }
    }

    long long sumDigitDifferences(vector<int>& nums) {
        ll n = nums.size();

        // Populate the `mp` map with frequencies
        for (int i = 0; i < n; i++) {
            f(nums[i]);
        }

        ll ans = 0;

        // Traverse the outer map
        for (auto& it : mp) {
            auto& innerMap = it.second; // Get the inner map
            if (innerMap.size() < 2) {
                continue; // If there's only one digit or no digits, skip
            }

            // Pairwise product of frequencies
            ll sumPairs = 0;
            for (auto it1 = innerMap.begin(); it1 != innerMap.end(); ++it1) {
                auto it2 = it1;
                for (++it2; it2 != innerMap.end(); ++it2) {
                    sumPairs += (ll)(it1->second) * (it2->second); // Multiply frequencies
                }
            }

            ans += sumPairs; // Add the sum of pairwise products for this inner map
        }

        return ans;
    }
};

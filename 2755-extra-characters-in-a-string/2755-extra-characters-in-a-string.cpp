class Solution {
public:
    int n;
    vector<int> k; // Dynamic programming memoization array
    int mincount = INT_MAX; // Initialize mincount to a large value

    int t(int idx, string& s, unordered_set<string>& st) {
        if (idx == n) {
            return 0; // If we reach the end of the string, no extra characters needed
        }

        if (k[idx] != -1) {
            return k[idx]; // Return cached result if already computed
        }

        int count = INT_MAX; // Initialize count to a large value

        for (int j = 1; j <= n - idx; j++) { // Ensure we do not go out of bounds
            string z = s.substr(idx, j); // Get substring from idx to idx+j

            if (st.count(z)) { // If the substring is found in the dictionary
                count = min(count, t(idx + j, s, st)); // No extra characters needed for this segment
            } else {
                count = min(count, j + t(idx + j, s, st)); // Count extra characters needed
            }
        }

        return k[idx] = count; // Cache and return the result
    }

    int minExtraChar(string s, vector<string>& dict) {
        n = s.size();
        k.assign(n + 1, -1); // Initialize vector with size n+1 and set all to -1
        unordered_set<string> st(dict.begin(), dict.end()); // Create set from dictionary
        
        return t(0, s, st); // Start recursive check from index 0
    }
};


class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> suspiciousMethods;
        suspiciousMethods.insert(k);
        bool changed = true;

        // Step 1: Keep marking suspicious methods while changes are happening
        while (changed) {
            changed = false;
            for (const auto& invocation : invocations) {
                int a = invocation[0]; // Method a invokes method b
                int b = invocation[1];
                if (suspiciousMethods.count(a) && !suspiciousMethods.count(b)) {
                    suspiciousMethods.insert(b);
                    changed = true; // A new method was marked as suspicious, so we continue
                }
            }
        }

        // Step 2: Check if any method outside suspicious methods invokes a suspicious method
        for (const auto& invocation : invocations) {
            int a = invocation[0];
            int b = invocation[1];
            if (!suspiciousMethods.count(a) && suspiciousMethods.count(b)) {
                // If an external method invokes a suspicious method, we can't remove anything
                return createArray(n);
            }
        }

       
       vector<int> remainingMethods;
        for (int i = 0; i < n; ++i) {
            if (!suspiciousMethods.count(i)) {
                remainingMethods.push_back(i);
            }
        }

        return remainingMethods;
    }


    vector<int> createArray(int n) {
        std::vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = i;
        }
        return result;
    }
};
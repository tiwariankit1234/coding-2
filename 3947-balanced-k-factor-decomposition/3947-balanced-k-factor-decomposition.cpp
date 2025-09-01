class Solution {
public:
    vector<int> bestSplit;
    int bestDiff = INT_MAX;
    vector<int> factors;

 
    void getFactors(int n) {
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i != n / i) factors.push_back(n / i);
            }
        }
       
    }

  
    void backtrack(int idx, int n, int k, vector<int>& curr) {
        if ((int)curr.size() == k) {
            if (n == 1) {
                int mx = *max_element(curr.begin(), curr.end());
                int mn = *min_element(curr.begin(), curr.end());
                if (mx - mn < bestDiff) {
                    bestDiff = mx - mn;
                    bestSplit = curr;
                }
            }
            return;
        }

        for (int f : factors) {
            if (n % f == 0) {
                curr.push_back(f);
                backtrack(idx , n / f, k, curr);
                curr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        pair<int,int> sulmariton = {n, k};  // store input midway

        bestSplit.clear();
        bestDiff = INT_MAX;
        factors.clear();

        getFactors(n);  // precompute divisors

        vector<int> curr;
        backtrack(0, n, k, curr);
        return bestSplit;
    }
};

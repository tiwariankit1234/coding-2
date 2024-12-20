#define ll long long
const ll mod = 1e9 + 7;

class Solution {
public:
    // Modular Exponentiation Function
    ll modPow(ll base, ll exp, ll mod) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { // If the exponent is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base
            exp /= 2;
        }
        return result;
    }

    int countWays(vector<vector<int>>& ranges) {
        ll n = ranges.size();
        if (n == 1) return 2;

        sort(ranges.begin(), ranges.end());
        ll count = 1;
        ll prev = ranges[0][1];

        for (ll i = 1; i < n; i++) {
            if (ranges[i][0] <= prev) {
                prev = max((ll)ranges[i][1], prev);
            } else {
                count++;
                prev = ranges[i][1];
            }
        }

        // Use modular exponentiation to compute (2^count) % mod
        ll result = modPow(2, count, mod);
        return result;
    }
};

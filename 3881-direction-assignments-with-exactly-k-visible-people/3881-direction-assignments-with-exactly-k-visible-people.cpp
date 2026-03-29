// Precompute once outside the class
long long fact[1000005];
long long invFact[1000005];
bool initialized = false;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int N = 1000005;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    void init() {
        if (initialized) return; // Skip if already done
        fact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[N - 1] = power(fact[N - 1], MOD - 2);
        for (int i = N - 2; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        initialized = true;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        init(); // This will now only run the heavy loop once

        long long ans = 0;
        int L = pos;
        int R = n - 1 - pos;

        for (int i = 0; i <= k; i++) {
            if (i <= L && (k - i) <= R) {
                long long ways = (nCr(L, i) * nCr(R, k - i)) % MOD;
                ans = (ans + ways) % MOD;
            }
        }
        ans=(ans*2)%MOD;
        
        // Note: Check your problem logic for this multiplication. 
        // Usually, combinations like this don't need a * 2 unless 
        // specified by the problem's specific arrangement rules.
        return (int)ans; 
    }
};
class Solution {
public:


long long nCr(int n, int r) {
    if(r > n) return 0;
    r = min(r, n - r);   // symmetry
    long long res = 1;

    for(int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}



    int uniquePaths(int m, int n) {
        int totallength=(m-1)+(n-1);
        return nCr(totallength,min(m,n)-1);
    }
};
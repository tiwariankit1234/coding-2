class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        double log4_x = log(n) / log(4);

        // Check if log4_x is an integer within a tiny error margin
        return fabs(log4_x - round(log4_x)) < 1e-10;
    }
};

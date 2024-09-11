class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorresult=start^goal;
        int count=0;
        // extracting last digit and see it is 1 by and operation
        while(xorresult!=0){
           xorresult=(xorresult)&(xorresult-1);
            count++;
        }
           return count;
    }
};
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorresult=start^goal;
        int count=0;
        while(xorresult){
            count+=xorresult&1;
            xorresult>>=1;
        }
           return count;
    }
};
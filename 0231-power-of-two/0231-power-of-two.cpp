class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if(n<0)return false;
        for (int i = 0; i < 32; i++) {
            int x = 1 << i;
          
            if (x == n) {

                return true;
            }
            
        }

        return false;
    }
};
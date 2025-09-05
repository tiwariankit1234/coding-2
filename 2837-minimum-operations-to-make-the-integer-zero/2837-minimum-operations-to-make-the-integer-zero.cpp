class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long k=0;
        while(true){
            long long val=((long long)num1-(long long)k*num2);
            if(val<0)return -1;
            if(( __builtin_popcountll(val))<=k and k<=(val))
            return k;

            k++;
        }
        return 0;
    }
};
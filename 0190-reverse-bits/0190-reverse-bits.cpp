class Solution {
public:
    int reverseBits(int n) {
        int num=0;
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
                num+=(1<<(31-i));
            }
        }
        return num;
    }
};
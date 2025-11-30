class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count=0;
        long long num=0;
        for(int i=0;i<k;i++){
        num=num*10+1;
        count++;
        if(num%k==0)return count;
        }
        return -1;
    }
};
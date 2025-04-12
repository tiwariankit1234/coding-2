class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        if(n<=2)return 2;
        bitset<64>bit;
        int index=0;
         for(int i=0;i<32;i++){
            if((1<<i)&n){
                index=i;
            }
         }
         return (int)(pow(2,index+1));
    }
};
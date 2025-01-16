class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32>b1(num1);
        bitset<32>b2(num2);
        bitset<32>b3(0);
        int setbits=b2.count();
        for(int i=31;i>=0;i--){
            if(b1[i]==1 and setbits){
                b3[i]=1;
                setbits--;
            }
        }
        for(int i=0;i<32;i++){
            if(b3[i]==0 and setbits){
                b3[i]=1;
                setbits--;
            }
        }
         unsigned long ul = b3.to_ulong();
         return ul;
        

    }
};
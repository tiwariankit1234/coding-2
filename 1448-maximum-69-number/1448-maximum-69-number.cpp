class Solution {
public:
    int maximum69Number (int num) {
        int k=0,index=-1;
        int x=num;
        while(num>0){
            int rem=num%10;
            num=num/10;
            if(rem==6){
             index=k;
            }
            k++;
        }
       
        index==-1?index=0:index=3*pow(10,index);
        return x+index;
    }
};
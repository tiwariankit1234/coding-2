class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int n=nums.size();
        int count5=0,count10=0,count20=0,remaining=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num==5){
                count5++;
            }
            else if(num==10){
                if(count5<=0)return false;
                count5--;
                count10++;
            }
            else{
                if(!(count5>=3 ||(count5>=1 and count10>=1)))return false;
                 if(count5>=1 and count10>=1){
                    count5-=1;
                    count10-=1;
                }
                else if(count5>=3){
                    count5-=3;
                }
                else{
                     cout<<"yahan se return hua hain"<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};
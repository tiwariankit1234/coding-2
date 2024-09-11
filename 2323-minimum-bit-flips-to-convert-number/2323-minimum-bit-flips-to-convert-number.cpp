class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        while(true and (start!=0)||(goal!=0)){
            int laststartdigit=start&1;
            int lastgoaldigit=goal&1;
            if(laststartdigit!=lastgoaldigit)count++;
            start=start>>1;
            goal=goal>>1;
        }
        return count;
    }
};
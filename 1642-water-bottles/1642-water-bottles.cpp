class Solution {
public:
    int numWaterBottles(int x, int y) {
        int count=x;
        int remaining=0;
        while(x>=y){
            cout<<x<<" "<<y<<" "<<count<<endl;
            int p=x/y;
            count+=p;
            remaining=(x%y);
               x=p+remaining;
        }
       
        return count;
    }
};
class Solution {
public:
    int mirrorDistance(int n) {
        int previousnum=0,currentnumber=0;
        int k=n;
        while(k>0){
            int currentdigit=k%10;
            currentnumber=previousnum*10+currentdigit;
            k=k/10;
            previousnum=currentnumber;
        }
        cout<<currentnumber<<endl;
        return abs(n-currentnumber);
    }
};
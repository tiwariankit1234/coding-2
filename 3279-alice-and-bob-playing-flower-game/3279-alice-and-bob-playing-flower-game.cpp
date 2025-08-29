#define ll long long

class Solution {
public:
    long long flowerGame(int n, int m) {
        ll oddcount=0,evencount=0,count=0;
        for(int i=1;i<=m;i++){
            if(i&1){
                oddcount++;
            }
            else{
                evencount++;
            }
        }
        for(int i=1;i<=n;i++){
            if(i&1){
             count=count+evencount;
            }
            else{
                count=count+oddcount;
            }
        }
        return count;
    }
};
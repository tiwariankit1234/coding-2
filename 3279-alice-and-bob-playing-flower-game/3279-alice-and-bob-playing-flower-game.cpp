#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll count=0,oddcount1=0,evencount1=0,oddcount2=0,evencount2=0;
        if(n&1){
            oddcount1=(n+1)/2;
            evencount1=n-oddcount1;
        }
        else{
            oddcount1=(n)/2;
            evencount1=(n)/2;
        }

         if(m&1){
            oddcount2=(m+1)/2;
            evencount2=m-oddcount2;
        }
        else{
            oddcount2=(m)/2;
            evencount2=(m)/2;
        }
       
        count=count+oddcount1*evencount2;
        count+=evencount1*oddcount2;
        return count;

    }
};
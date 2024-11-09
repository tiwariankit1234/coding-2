#define ll long long

class Solution {
public:
    long long minEnd(int n, int x) {
        if(n==1)return x;
        ll result=x;
      for(int i=1;i<n;i++){
        result=(result+1)|x;
      }
      return result;
    }
};
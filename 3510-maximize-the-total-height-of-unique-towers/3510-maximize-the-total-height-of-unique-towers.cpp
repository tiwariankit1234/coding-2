
#define ll long long

class Solution {
public:
    long long maximumTotalSum(vector<int>& height) {
        sort(height.begin(),height.end());
        ll n=height.size();

       int previousheight=height[n-1];
        ll maxheight=height[n-1];

        for(ll i=n-2;i>=0;i--){
          int currentheight=min(height[i],previousheight);
            if(currentheight==previousheight){
                currentheight-=1;
            }
            if(currentheight<=0)return -1;
            maxheight+=currentheight;
           previousheight=currentheight;
        
            }
            return maxheight;
        }
};
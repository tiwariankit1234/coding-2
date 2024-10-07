// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long int 
class Solution {
public:
    int firstBadVersion(int n) {
       ll low=1,high=n;
          
         ll ans=n;
        while(low<=high){
           ll mid=(low+(high-low)/2);
            if(isBadVersion(mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
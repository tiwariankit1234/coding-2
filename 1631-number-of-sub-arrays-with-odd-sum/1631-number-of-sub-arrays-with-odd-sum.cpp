int  mod= 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int oddcount=0,evencount=1,prefixsum=0,cnt=0;
        for(int i=0;i<n;i++){
            prefixsum+=arr[i];
            if(prefixsum&1){    // sum is odd see in the remaining array      how many evencount is there     
            oddcount++;
            cnt=(((cnt%mod)+(evencount)%mod)%mod);
            }
            else{
                evencount++;
                cnt=((cnt%mod)+(oddcount%mod)%mod);
            }
        }
        return cnt;
    }
};
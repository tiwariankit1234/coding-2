#define ll long long 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>prefixmax(n),suffixmax(n);
        prefixmax[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixmax[i]=max((ll)nums[i],prefixmax[i-1]);
        }
        for(auto it:prefixmax)
        cout<<it<<" ";

        cout<<endl;
          suffixmax[n-1]=nums[n-1];
          for(int i=n-2;i>=0;i--){
            suffixmax[i]=max((ll)nums[i],suffixmax[i+1]);
          }

           for(auto it:suffixmax)
        cout<<it<<" ";

        cout<<endl;

        ll ans=INT_MIN;
          for(int i=1;i<n-1;i++){
           ll k=(prefixmax[i-1]-nums[i])*suffixmax[i+1];
           if(k<0)k=0;
            ans=max(k,ans);
          }
          return ans;
    }
};
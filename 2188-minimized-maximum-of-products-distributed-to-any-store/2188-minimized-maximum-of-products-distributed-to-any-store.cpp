#define ll long long 
class Solution {
public:

bool possible(vector<int>&arr,ll mid,ll k){
  ll count=0;
    ll n=arr.size();
    for(ll i=0;i<n;i++){
        ll q=arr[i];
        while(q>0){
            q-=mid;
            // cout<<count<<endl;
            count++;
        }
      
    }
      if(count>k)return false;
        else
        return true;
}
    int minimizedMaximum(int  k, vector<int>& arr) {
        
       ll l=1,h=1e9;
   ll ans=0;       // you cannot take low=0 because
   // for test case 7 7   1 17 14 9 15 9 14 answer will go below 9  but 9 can never be answer
   // min(max)
   cout<<h<<endl;
   while(l<=h){
       ll mid=(l+h)/2;
    //    cout<<mid<<endl;
       if(possible(arr,mid,k)){
             ans=mid;
          h=mid-1; 
        
       }
       else {
           l=mid+1;
           
       }
   }
      return ans;
    }
};
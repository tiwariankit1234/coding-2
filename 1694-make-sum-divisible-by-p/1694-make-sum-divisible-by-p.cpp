#define ll long long


class Solution {
public:
  ll minSubarray(vector<int>& nums, int p) {
       ll n=nums.size();

     
        
        ll sum=0;
       for(int i=0;i<n;i++){
        sum+=(nums[i])%p;
       }
          
        if(sum%p==0)return 0;
       

      

      
        
        cout<<"5"<<endl;
      ll currentsum=0;
      ll target=sum%p;
        target=target%p;

     

        unordered_map<ll,ll>mp;
        mp[0]=-1;
       
      ll minlen=n;
      ll len=0;
         
         cout<<"5"<<endl;

       
        for(int i=0;i<n;i++){
           currentsum=(currentsum+nums[i])%p;
         ll required=(currentsum-target+p)%p;
           if(mp.find(required)!=mp.end()){
             len=i-mp[required];
             minlen=min(len,minlen);
           }
           mp[currentsum]=i;
        }


         return (minlen==n)?(-1):minlen;
    }
};
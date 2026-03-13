
#define ll long long 

class Solution {
public:


   bool check(ll seconds,vector<int>& arr,ll mountainHeight){
     
  
     // each worker take arr[i]*(x*(x+1))/2 time to reduce height x
     // binary search on height x
       // har worker given seconds me maximum height reduce karna chata hain
     for(int i=0;i<arr.size();i++){
         ll low=0,high=1e6;
      ll ans;
     while(low<=high){
      ll mid=(low+high)/2; // itni height 
       ll time_required = mid * (mid + 1) / 2;
        if((time_required)<=(seconds/arr[i])){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
     }
     mountainHeight-=ans;
   }
   if(mountainHeight<=0)return true;
   else
   return false;
   }


    long long minNumberOfSeconds(int mountainHeight, vector<int>& arr) {
        //binary search on seconds;

      ll low=0,high=1e16;
       ll ans;
        while(low<=high){
          ll mid=low+(high-low)/2;
            // function to check whethercan we reduce mountain height within mid second
            // min(max(time))


            if(check(mid,arr,mountainHeight)){
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
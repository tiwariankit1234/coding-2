#define ll long long int
class Solution {
public:
bool f(ll time,vector<int>&ranks,int k){
    int n=ranks.size();
     ll totalcars=0;
     for(int i=0;i<n;i++){
        
        totalcars+=(ll)(floor(sqrt(time/(ll)ranks[i])));
      
        if(totalcars>=k)return true;
     }
     return false;
}
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        ll l=1,h=(ll)(*min_element(ranks.begin(),ranks.end()))*(ll)(cars)*(ll)cars;
        ll ans;
        while(l<=h){
            ll mid=(l)+(h-l)/2;
            if(f(mid,ranks,cars)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
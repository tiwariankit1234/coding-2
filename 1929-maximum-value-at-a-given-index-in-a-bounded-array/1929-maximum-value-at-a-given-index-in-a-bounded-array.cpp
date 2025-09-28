#define ll long long
class Solution {
public:
ll getsum(ll count,ll val){
    return (val*count)-(count*(count+1))/2;
}
    int maxValue(int n, int index, int maxsum) {
        ll l=1,h=maxsum,ans=0;
        while(l<=h){
            ll mid=(l+h)/2;
            //left sum
            ll leftcount=min((ll)index,mid-1);
            // itne elements ka sum nikalna hain
            ll leftsum=getsum(leftcount,mid)+max((ll)(0),(index)-(mid-1));
               
            // rightsum
            ll rightcount=min((ll)(n-index-1),mid-1);
            ll rightsum=getsum(rightcount,mid)+max((ll)0,(n-(index+1))-(mid-1));


            if(leftsum+rightsum+mid<=maxsum){
               ans=max(ans,mid);
               l=mid+1;
            }
            else{
                h=mid-1;
            }

        }
        return ans;
    }
};
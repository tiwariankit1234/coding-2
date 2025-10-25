class Solution {
public:
bool findDays(vector<int>&weights,int mid,int days){
    int ndays=0,n=weights.size(),currentwt=0;
    for(int i=0;i<n;i++){
         currentwt+=weights[i];
        if(currentwt>mid){
            currentwt=weights[i];
            ndays++;
        }
    }
    ndays++;
    if(mid==11)cout<<ndays<<endl;
    if(ndays==0)return true;
    if(ndays<=days)return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0),ans=0;
    while (low <= high) {
        int mid = (low + high) / 2;
       
        if (findDays(weights,mid,days)) {
            //eliminate right half
            ans=mid;
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return ans;
    }
};
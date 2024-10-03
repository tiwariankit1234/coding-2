class Solution {
public:

 bool check(int mid,vector<int>& arr,int m,int k){
    
    int boquets=0;
    int currentcount=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=mid){
            currentcount++;
        }
       
         else{
           currentcount=0;
         }

         if(currentcount==k){
         boquets++;
         currentcount=0;
         }

    }

    cout<<mid<<" "<<boquets<<endl;
    if(boquets<m)return false;
    else
    return true;
 }

    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();

        int low=1,high=*max_element(arr.begin(),arr.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(mid,arr,m,k)){
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
class Solution {
public:

      bool possible(int mid,vector<int>& nums,int maxoperations){
        int operations=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            operations+=((nums[i]-1)/mid);
        
        }
        cout<<"operations"<<" "<<operations<<endl;
        if(operations<=maxoperations)return true;
        else
        return false;

      }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,nums,maxOperations)){
                cout<<"mid"<<" "<<mid<<endl;
                  ans=mid;
                high=mid-1;
            }
            else{
                  cout<<"mid"<<" "<<mid<<endl;
                low=mid+1;
            }
        
        }
            return ans;
    }
};
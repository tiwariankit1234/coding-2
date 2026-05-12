class Solution {
public:
bool possible(int mid,vector<vector<int>>& tasks){
    for(auto &temp:tasks){
        int x=temp[0],y=temp[1];
        if(mid>=y){
         mid=mid-x;
        }
        else{
            return false;
        }
    }
    return mid>=0?true:false;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
           
            return a[1]-a[0]>(b[1]-b[0]);
        });
        int  low=1,high=INT_MAX,ans=INT_MAX;
        while(low<=high){
            int mid=(low+(high-mid)/2);
            if(possible(mid,tasks)){
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
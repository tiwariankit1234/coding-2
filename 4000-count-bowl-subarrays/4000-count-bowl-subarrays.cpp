#define ll long long 
class Solution {
public:
void prevgreater(vector<int>&nums,vector<int>&prev){
    int n=nums.size();
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++){
        int num=nums[i];
        while(!st.empty() and num>nums[st.top()]){
            st.pop();
        }
        if(st.empty())prev[i]=-1;
        else{
          prev[i]=st.top();
        }
        st.push(i);
    }
    return ;
}

void nextgreater(vector<int>&nums,vector<int>&next){
    int n=nums.size();
    stack<int>st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        int num=nums[i];
        while(!st.empty() and num>nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            next[i]=st.top();
        }
        st.push(i);
    }
    return ;
}
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        ll count=0;
        // prev greater element
        vector<int>prev(n,-1),next(n,-1);
          prevgreater(nums,prev);
          nextgreater(nums,next);
        //   for(auto it:prev){
        //     cout<<it<<" ";
        //   }
        //   cout<<endl;
        //   for(auto it:next){
        //     cout<<it<<" ";
        //   }
          cout<<endl;
        for(int i=1;i<(n-1);i++){
            if(prev[i]!=-1 and next[i]!=-1){
                count++;
            }
        }
        return count;

    }
};
#define ll long long
class Solution {
public:

vector<ll>nextgreater(vector<int>&arr){
int n=arr.size();
 stack<int>st;
    vector<ll> nge(arr.size(),LLONG_MAX);

   st.push(arr[n-1]);
   for(int i=n-2;i>=0;i--)
   {
    //pop aal the elements smaller than arr[i]
    while(st.size()>0 && st.top()<=arr[i])
    {
        st.pop();
    }
    //mark the answer in nge array
    if(!st.empty()){
        nge[i]=st.top();
    }
    //push the arr[i]
    st.push(arr[i]);
   }

   return nge;
}  

vector<ll> prevSmaller(vector<int> &arr) {
    int n = arr.size();
    vector<ll> result(n, LLONG_MIN); // Default to -1 if no smaller element exists
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}


    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<ll>next=nextgreater(nums);
        vector<ll>prev=prevSmaller(nums);
        // for(auto it:next)
        // cout<<it<<" ";

        // cout<<endl;

        // for(auto it:prev)
        // cout<<it<<" ";

        cout<<endl;
        for(int i=0;i<n;i++){
            if(next[i]!=LLONG_MAX and prev[i]!=LLONG_MIN)
            return  true;
        }
        return  false;
    }
};
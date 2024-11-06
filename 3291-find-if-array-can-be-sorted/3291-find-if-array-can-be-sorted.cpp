class Solution {
public:
    bool canSortArray(vector<int>& ans) {
          int n=ans.size();
    for(int i=n-1;i>=1;i--){
        int didswap=0;     // agar no swap then break the loop
       for(int j=0;j<=i-1;j++){
        if(ans[j]>ans[j+1] and __builtin_popcount(ans[j])==__builtin_popcount(ans[j+1])){
            swap(ans[j],ans[j+1]);
            didswap=1;
        }
       }
       if(didswap==0)
       break;
    }

    for(int i=0;i<n-1;i++){
        if(ans[i+1]<ans[i]){
            return false;
        }
    }
    return true;
    }
};
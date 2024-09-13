class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //pehle ek ans vector initialise karenge
        // then traverse query vector 
        // for(each i we will be storing value in ans vector)
        int n=arr.size();
        int k=queries.size();
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            int firstindex=queries[i][0];
            int secondindex=queries[i][1];
            int temp=0;
            for(int j=firstindex;j<=secondindex;j++){
              temp=temp^arr[j];
            }
            ans[i]=temp;
            // if(firstelement==secondelement){
            //     ans[i]=firstelement;
            // }
            // else{
            //  ans[i]=firstelement^secondelement;
            // }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newarr) {
        int n=arr.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<n and arr[i][1]<newarr[0]){
            ans.push_back(arr[i]);
          i++;
        }
        while(i<n and arr[i][0]<=newarr[1]){
            newarr[0]=min(newarr[0],arr[i][0]);
            newarr[1]=max(newarr[1],arr[i][1]);
            i++;
        }
       ans.push_back(newarr);
         while(i<n){
            ans.push_back(arr[i]);
          i++;
        }
        return ans;

    }
};
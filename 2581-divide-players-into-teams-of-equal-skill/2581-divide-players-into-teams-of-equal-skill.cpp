class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int sum=arr[0]+arr[n-1];
          long long productskill=(arr[0]*arr[n-1]);
           
           int i=1,j=n-2;
          while(i<j){
             int newsum=arr[i]+arr[j];
             if(newsum!=sum)return -1;
             productskill+=arr[i]*arr[j];

             i++;
             j--;
          }
          return productskill;
    }
};
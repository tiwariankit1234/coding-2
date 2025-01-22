class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;

        sort(arr.begin(),arr.end());

       int prevstart=arr[0][0];
       int prevend=arr[0][1];
         cout<<"run befor loop"<<endl;
         ans.push_back({prevstart,prevend});

        for(int i=1;i<n;i++){
            int start=arr[i][0];
            int end=arr[i][1];
            cout<<"isindexpar chl raha"<<" "<<i<<endl;
            // check merged condition
            if(start<=prevend){
              
             
              ans.back()[1]=max(prevend,end);
              prevend=max(end,prevend);
            }
            else{
                ans.push_back({start,end});
                prevstart=start;
                prevend=end;
            }
   
        }
        return ans;
    }
};
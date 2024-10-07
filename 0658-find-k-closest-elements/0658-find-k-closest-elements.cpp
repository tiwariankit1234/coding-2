class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++){
          int difference=(abs)(arr[i]-x);
          pq.push({difference,arr[i]});
        }
        cout<<"5"<<endl;
          
          vector<int>ans;

        while(k>0){
          auto it=pq.top();
          int element=it.second;
          pq.pop();
          ans.push_back(element);
          k--;
        }

       sort(ans.begin(),ans.end());
        return ans;
    }
};
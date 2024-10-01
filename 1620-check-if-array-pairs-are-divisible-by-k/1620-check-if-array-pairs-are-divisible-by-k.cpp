class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
              arr[i]= ((arr[i] % k) + k) % k;
            mp[arr[i]]++;
           
        }
         if((mp[0]%2)!=0)return false;
          int pairs=0;
        for(int i=1;i<=k/2;i++){
             int num=i;
             int complement=k-num;
            if(mp[num]!=mp[complement])return false;
        }

       ;
       
       return true;
        
    }
};
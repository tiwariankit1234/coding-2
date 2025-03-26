class Solution {
public:

int f(int x,int median,int k){
    int count=0;
    if(median>x){
        // cout<<median<<" "<<x<<" "<<k<<endl;
        while((x+k)<=median){
          count++;
          
          x+=k;
        }
        return count;
    }
     if(median==x){
        return 0;
    }
    if(median<x){
        while(x-k>=median){
            count++;
          x-=k;
        }
        return count;
    }
    return  0;
}
    int minOperations(vector<vector<int>>& grid, int x) {
    
        vector<int>ans;
        for(auto it:grid){
            for(auto k:it)
            ans.push_back(k);
        }
        int n=ans.size();
        int rem=grid[0][0]%x;
        for(auto k:ans){
         if((k%x)!=rem)return -1;
        }
        sort(ans.begin(),ans.end());
        
        int median=ans[n/2];

   
        int count=0;
        cout<<median<<endl;
        for(int i=0;i<n;i++){
          count += abs(ans[i] - median) / x;
        }
          return count;
    }
};
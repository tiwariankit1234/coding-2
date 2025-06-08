class Solution {
public:
int f(int num,unordered_map<int,int>&mp){
    int k=sqrt(num);
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(num%i==0){
           if(mp.find(i)!=mp.end()){
             ans=min(ans,mp[i]);
           }
           int m=num/i;
           if(mp.find(m)!=mp.end()){
            ans=min(ans,mp[m]);
           }
        }
    }
    if(ans==INT_MAX)return -1;
    return ans;
}
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int m=groups.size();
         int n=elements.size();
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            if(mp.find(elements[i])==mp.end()){
                mp[elements[i]]=i;
            }
         }
         vector<int>ans(m,-1);
         for(int i=0;i<m;i++){
           ans[i]=f(groups[i],mp);
         }
         return ans;
    }
};
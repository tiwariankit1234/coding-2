class Solution {
public:
 
 void f(int i,int n,vector<int>&ans){
    if(i>n)return ;
    ans.push_back(i);
    
    for(int j=0;j<=9;j++){
        int nextnumber=i*10+j;
        if(nextnumber<=n){
            f(nextnumber,n,ans);
        }
    }
 }
 
 
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            if(i<=n)
            f(i,n,ans);
        }
        
        return ans;
    }
};
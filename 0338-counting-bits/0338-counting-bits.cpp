class Solution {
public:
int f(int i){
    if(i==0)return 0;
    if(i==1)return 1;
    if(i==2)return 1;
    if(i==3)return 2;
    if(i==4)return 1;
     if(i&1)return f(i/2)+1;
     else
     return f(i/2);

}
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<(n+1);i++){
            ans[i]=f(i);
        }
        return ans;
    }
};
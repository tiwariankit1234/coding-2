class Solution {
public:
vector<string>ans;
void f(string s,int idx,int n){
    if(s.size()==n){
        ans.push_back(s);
        return ;
    }
       if(idx>=1){
        char previouschar=s[idx-1];
        for(char i='a';i<='c';i++){
            if(i!=previouschar)
            f(s+i,idx+1,n);
        }
       }
       else{
          for(char i='a';i<='c';i++){
            f(s+i,idx+1,n);
        }
       }
    return ;
}
    string getHappyString(int n, int k) {
         
        f("",0,n);
        
        sort(ans.begin(),ans.end());
          if(k>ans.size())return "";
        return ans[k-1];
    }
};
class Solution {
public:
vector<string>ans;
int k;
void generate(int count1,int count2,string s){
    if(count1<count2)return ;
    if(count1>k || count2>k)return ;
    if(count1==k and count2==k){
        cout<<s<<endl;
        ans.push_back(s);
        return ;
    }
  
     generate(count1+1,count2,s+'(');
     generate(count1,count2+1,s+')');
     return ;
}
    vector<string> generateParenthesis(int n) {
        k=n;
        generate(0,0,"");
        return ans;
    }
};
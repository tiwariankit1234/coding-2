class Solution {
public:

int k;
 void f(int count1,int count2,int idx,string s,vector<string>&ans){
    //base case
    if(idx==(2*k)){
        ans.push_back(s);
        return ;
    }

    // check each valid possibility 
    // when we take '(' character
    if((count1)<k){
        
      
        f(count1+1,count2,idx+1,s+'(',ans);
    }

    if((count2)<(count1)){
      
     
       f(count1,count2+1,idx+1,s+')',ans);
    }
   
 }

    vector<string> generateParenthesis(int n) {
            int count1=0,count2=0,idx=0;
            vector<string>ans;
            string s="";
            k=n;
       f(count1,count2,idx,s,ans);
       return ans;
        
    }
};
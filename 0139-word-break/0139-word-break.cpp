class Solution {
public:

   
   
 int n;
 int k[301];
 bool t(int idx,string& s,unordered_set<string>&st){
    if(idx==n){
        return k[idx]=true;
    }
     
     if(k[idx]!=-1)
     return k[idx];

  for(int j=1;j<=n;j++){
    string z=s.substr(idx,j);
  
    if(st.contains(z) and t(idx+j,s,st)){
        return k[idx]=true;
    }
 
  }
  return k[idx]=false;
 }
    
    bool wordBreak(string s, vector<string>& dict) {
      n=s.size();
      memset(k,-1,sizeof(k));
        unordered_set<string>st(dict.begin(),dict.end());
        // first create set
        // ek bool function that given string is present in the dict or not 
        return t(0,s,st);
    }
};
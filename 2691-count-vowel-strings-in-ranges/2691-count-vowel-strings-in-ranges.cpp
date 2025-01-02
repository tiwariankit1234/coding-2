class Solution {
public:
bool check(string &fir){
    int n=fir.size();
    if((fir[0]=='a' || fir[0]=='e'||fir[0]=='i'||fir[0]=='o'||fir[0]=='u') and (fir[n-1]=='a' ||fir[n-1]=='e' ||fir[n-1]=='i'||fir[n-1]=='o'||fir[n-1]=='u'))
    return true;

    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
      
        int n=words.size();
           vector<int>ans(queries.size(),0);
        vector<int>prefixsum(n+1,0);
        string fir=words[0];
        if(check(fir)){
            prefixsum[1]=1;
        }
        else{
            prefixsum[1]=0;
        }
        for(int i=1;i<n;i++){
          if(check(words[i])){
            prefixsum[i+1]=1+prefixsum[i];
          }
          else{
            prefixsum[i+1]=0+prefixsum[i];
          }
        }
        int i=0;
        for(auto it:queries){
            int first=it[0];
            int second=it[1];
           ans[i++]=prefixsum[second+1]-prefixsum[first];
        }
        return ans;
    }
};
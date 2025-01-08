class Solution {
public:
bool check(string s,string t){
    if(t.size()<s.size())return false;
    int k=s.size();
    int i=0;
    while(i<k){
        if(s[i]!=t[i])
        return false;
        i++;
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
       i=0;
      while(i<k){
        if(s[i]!=t[i])
        return false;
        i++;
      }
      return true;

}
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};
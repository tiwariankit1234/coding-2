class Solution {
public:
bool check(string s,string t){
    if(t.size()<s.size())return false;
    int l1=0,r1=0,l2=s.size()-1,r2=t.size()-1;
    bool flag=true;
    for( l1,r1,l2,r2;(l1<(s.size()) and r1<(t.size()) and flag and (l2>=(0)) and (r2>=0) );l1++,r1++,l2--,r2--){
        if(s[l1]!=t[r1]){
            flag=false;
        }
        if(s[l2]!=t[r2])
        flag=false;
    }
    return flag;
   

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
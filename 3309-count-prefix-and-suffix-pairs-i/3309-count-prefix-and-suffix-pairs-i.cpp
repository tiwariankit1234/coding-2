class Solution {
public:
bool check(string s,string t){
    if(t.size()<s.size())return false;
    int k=s.size();
    if(t.find(s)==0 and t.rfind(s)==(t.size()-s.size()))
    return true;

    return false;
   

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
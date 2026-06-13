class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        int sum=0;
        for(string word:words){
            int s=0;
            for(char c:word){
                s+=weights[c-'a'];
            }
             s=s%26;
             ans+=char('z'-s);
        }
        return ans;
    }
};
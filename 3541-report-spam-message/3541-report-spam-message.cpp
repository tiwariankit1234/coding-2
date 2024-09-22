class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int n=message.size();
        int k=bannedWords.size();
        unordered_set<string>s(bannedWords.begin(),bannedWords.end());
        int count=0;
        for(auto it:message){
            if(s.contains(it)){
                count++;
            }
            if(count>=2)return true;
        }
        return false;
    }
};
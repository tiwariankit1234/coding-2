class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words(wordDict.begin(),wordDict.end());
        queue<int>q;
        vector<bool>seen(s.length(),false);
        int start=0;
        q.push(start);
        int n=s.length();
        while(q.size()>0){
            int start=q.front();
            q.pop();
            
            if(start==s.length())return true;
            for(int end=start+1;end<=n;end++){

                 if (seen[end]) {
                    continue;
                }
                if(words.find(s.substr(start,end-start))!=words.end()){
                    q.push(end);
                    seen[end]=true;
                }
            }
       
        }
        return false;
    }
};
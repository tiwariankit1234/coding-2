class Solution {
public:
    bool equalFrequency(string word) {
        int n=word.size();
        map<char,int>mp;

        for(char c:word)
        mp[c]++;

        for(auto it=mp.begin();it!=mp.end();it++){
             mp[it->first]--;
             // check equal frequencies are there or not
            //  int count=0;
            //    int freq=it->second;
            //  for(auto it=mp.begin();it!=mp.end();it++){
            //     if(it->second==freq)
            //     count++;
            //  }
            //  if(count==mp.size())return true;

            set<int>s;
            for(auto it:mp){
                if(it.second>0)
                s.insert(it.second);
            }
            if(s.size()==1)return true;

             mp[it->first]++;
        }
        return false;
    }
};
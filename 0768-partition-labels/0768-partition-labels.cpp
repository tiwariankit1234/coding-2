class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(char c:s)
        mp[c]++;
            vector<int>flag(26,false);
        vector<int>ans;
        int prevans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]--;
            flag[s[i]-'a']=true;
            bool t=true;;
             for(int j=0;j<26;j++){
                if(flag[j]==true){
                    if(mp[j+'a']!=0){
                        t=false;
                        break;
                    }
                }
             }
             if(t){ans.push_back(i+1-prevans);
            prevans=i+1;
        }
        }
        return ans;
    }
};
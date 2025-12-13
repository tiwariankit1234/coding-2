class Solution {
public:
    vector<int> countMentions(int n,
                              vector<vector<string>>& events) {
        vector<int> nousers(n, 0);
        sort(events.begin(),events.end(),[](vector<string>&a,vector<string>&b){
            string t=a[1];
            string p=b[1];
             int k=stoi(t);
             int m=stoi(p);
             if(k!=m)return k<m;
             return a[0]=="OFFLINE" and b[0]=="MESSAGE";
        });
       
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[i] = -60;
        }

        for (auto it : events) {
            string t = it[0];
            string q = it[1];
            int timestamp=stoi(q);
            string p = it[2];
            if (t == "MESSAGE") {
                if (p == "HERE") {
                    for (auto [x, y] : mp) {
                        if (timestamp >= y + 60) {
                            nousers[x]++;
                        }
                    }
                } else if (p == "ALL") {
                    for (int i = 0; i < nousers.size(); i++) {
                        nousers[i]++;
                    }
                } else {
                    stringstream ss(p);
                    string t;
                    vector<string>ans;
                    while(ss>>t){
                      ans.push_back(t);
                    }
                    int i=0;
                      int k = ans.size();
                    while (i < k) {
                         string m=ans[i];
                        int id = stoi(m.substr(2));
                            nousers[id]++;
                        
                        i+=1;
                    }
                }
            } else {
              
                int id=stoi(p);
                mp[id]=timestamp;
            }
        }
        return nousers;
    }
};
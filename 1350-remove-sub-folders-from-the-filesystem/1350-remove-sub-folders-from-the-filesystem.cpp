class Solution {
public:
    bool found(string& p, unordered_set<string>& s) {
        int n = p.size();
        if (p == "/")
            return true;

        int idx = -1;
        string x = "";
        for (int i = 0; i < n; i++) {
            // cout<<p<<" "<<i<<" "<<x<<endl;
            if (i == 0) {
                x += p[i];
            } else if (p[i] == '/') {
                if (s.find(x) != s.end())
                    return true;

                x += '/';
            } else {
                x += p[i];
            }
        }

        return false;
    }
    vector<string> removeSubfolders(vector<string>& temp) {
        int n = temp.size();
        sort(temp.begin(),temp.end());
        unordered_set<string> s;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                s.insert(temp[i]);
                ans.push_back(temp[i]);
            } else {
                if (!found(temp[i], s)) {
                    ans.push_back(temp[i]);
                    s.insert(temp[i]);
                }
            }
        }
        return ans;
    }
};
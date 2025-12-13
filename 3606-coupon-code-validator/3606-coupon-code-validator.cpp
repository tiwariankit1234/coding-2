class Solution {
public:
    bool isValidcode(string& s) {
        if (s.size() == 0)
            return false;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ((s[i] >= 'a' and s[i] <= 'z') ||
                (s[i] >= 'A' and s[i] <= 'Z') ||
                (s[i] >= '0' and s[i] <= '9') ||s[i]=='_') {

            } else {
                return false;
            }
        }
        return true;
    }

        bool isValidbusiness(string & t) {
            if(!(t == "electronics" || t == "grocery" || t == "pharmacy" ||
                 t == "restaurant")) return false;
            return true;
        }
        vector<string> validateCoupons(vector<string> & code,
                                       vector<string> & businessLine,
                                       vector<bool> & isActive) {
            int n = code.size();
            vector<pair<string, string>> ans;
            for (int i = 0; i < n; i++) {
                if (isValidcode(code[i]) and
                    isValidbusiness(businessLine[i]) and isActive[i] == true) {
                    ans.push_back({businessLine[i], code[i]});
                }
            }
            sort(ans.begin(), ans.end());
            vector<string> temp;
            for (auto it : ans) {
                temp.push_back(it.second);
            }
            return temp;
        }
    };
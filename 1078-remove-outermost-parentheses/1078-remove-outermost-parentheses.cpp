class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        int n = s.size();
        string t = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (count==0) {
                    count++;
                   
                } else {
                    t.push_back(s[i]);
                  
                    count++;
                }
            } else {
                count--;
               
                if (count!=0) {
                    t.push_back(s[i]);
                }
            }
        }
        return t;
    }
};
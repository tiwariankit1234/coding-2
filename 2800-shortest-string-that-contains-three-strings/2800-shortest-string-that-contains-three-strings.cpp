class Solution {
public:
    // Helper function to merge two strings optimally
    string mergeTwo(string s1, string s2) {
        // Step 1: Check if s2 is already inside s1
        if (s1.find(s2) != string::npos) return s1;
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        // Step 2: Max overlap dhundne ke liye suffix aur prefix match karein
        // Hum maximum possible length se start karenge
        for (int len = min(n1, n2); len > 0; --len) {
            // Suffix of s1 vs Prefix of s2
            if (s1.substr(n1 - len) == s2.substr(0, len)) {
                return s1 + s2.substr(len);
            }
        }
        
        // Step 3: Agar koi overlap nahi mila, toh simply concatenate
        return s1 + s2;
    }

    string f(string a, string b, string c) {
        // Pehle a aur b ko merge karke plomaresto mein store karte hain
        string plomaresto = mergeTwo(a, b);
        
        // Fir plomaresto aur c ko merge karke final result return karte hain
        return mergeTwo(plomaresto, c);
    }

    string minimumString(string a, string b, string c) {
        string ans = "";
        
        // Hum saare 6 permutations check karenge
        vector<string> perms = {
            f(a, b, c), f(a, c, b),
            f(b, a, c), f(b, c, a),
            f(c, a, b), f(c, b, a)
        };

        for (string& res : perms) {
            if (ans == "") {
                ans = res;
            } else {
                // Pehle length check karein, fir lexicographical order
                if (res.size() < ans.size()) {
                    ans = res;
                } else if (res.size() == ans.size() && res < ans) {
                    ans = res;
                }
            }
        }
        return ans;
    }
};
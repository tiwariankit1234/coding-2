class Solution {
public:
    int f(const string& s) {
        int count = 0;
        for (char ch : s) {
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                count++;
        }
        return count;
    }

    string reverseWords(string s) {
        stringstream ss(s);
        string t;

        // get first word
        if (!(ss >> t)) return "";

        int vowcount = f(t);
        string res = t;

        // process remaining words
        while (ss >> t) {
            if (f(t) == vowcount)
                reverse(t.begin(), t.end());
            res += " " + t;
        }

        return res;
    }
};

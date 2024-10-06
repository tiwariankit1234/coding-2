#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        deque<string> dq1, dq2;
        string s = "";

        // Split the first sentence into words
        for (int i = 0; i < m; i++) {
            if (s1[i] != ' ') {
                s += s1[i];
            } else if (!s.empty()) {
                dq1.push_back(s);
                s = "";
            }
        }
        if (!s.empty()) dq1.push_back(s); // Push the last word

        // Reset and split the second sentence into words
        s = "";
        for (int i = 0; i < n; i++) {
            if (s2[i] != ' ') {
                s += s2[i];
            } else if (!s.empty()) {
                dq2.push_back(s);
                s = "";
            }
        }
        if (!s.empty()) dq2.push_back(s); // Push the last word

        cout << dq1.size() << " " << dq2.size() << endl;

        // Compare from the front
        while (!dq1.empty() && !dq2.empty()) {
            string first = dq1.front();
            string second = dq2.front();
            if (first != second) break;
            else {
                dq1.pop_front();
                dq2.pop_front();
            }
        }

        cout << dq1.size() << " " << dq2.size() << endl;

        // Compare from the back
        while (!dq1.empty() && !dq2.empty()) {
            string first = dq1.back();
            string second = dq2.back();
            if (first != second) break;
            else {
                dq1.pop_back();
                dq2.pop_back();
            }
        }

        // Check if all remaining words in the longer sentence can be matched
        return (dq1.empty() || dq2.empty());
    }
};

// Example usage

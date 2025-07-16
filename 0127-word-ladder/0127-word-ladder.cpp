class Solution {
public:
    bool isbeginWordpresent(string& neword, string& endWord,
                            vector<string>& wordList, unordered_set<string>& s,
                            unordered_set<string>& t) {

        int n = wordList.size();

        if (s.find(neword) != s.end() and (t.find(neword) == t.end())) {

            t.insert(neword);
            return true;
        } else
            return false;

        cout << endl;
    }

    int bfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_set<string> t;

        queue<pair<string, int>> q;
        int n = beginWord.size();
        q.push({beginWord, 1});
        string word = "";
        int number = 0;
        while (q.size() > 0) {
            word = q.front().first;

            number = q.front().second;
            if (word == endWord)
                return number;
            q.pop();
            string dword = word;
            for (int i = 0; i < n; i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    dword = word;
                    dword[i] = ch;
                    if (isbeginWordpresent(dword, endWord, wordList, s, t)) {
                        q.push({dword, number + 1});
                    }
                }
            }
        }
        //  cout<<endl;
        return 0;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        return bfs(beginWord, endWord, wordList);
    }
};
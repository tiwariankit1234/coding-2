class Solution {
public:
    bool areSentencesSimilar(string a, string b) {
        stringstream s(a),ss(b);
        string str;
        deque<string>d1,d2;
        while(s>>str)d1.push_back(str);
        while(ss>>str)d2.push_back(str);

        while(!d1.empty() and !d2.empty() and d1.front()==d2.front())d1.pop_front(),d2.pop_front();
        while(!d1.empty() and !d2.empty() and d1.back()==d2.back())d1.pop_back(),d2.pop_back();

        return d1.empty() || d2.empty();
    }
};
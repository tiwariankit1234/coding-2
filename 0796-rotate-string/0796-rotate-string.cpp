class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        string t=s+s;
        if(t.find(goal)!=string::npos)return true;
        return false;
    }
};
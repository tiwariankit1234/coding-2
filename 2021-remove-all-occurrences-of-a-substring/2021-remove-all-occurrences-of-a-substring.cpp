class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
       while(true){
        size_t idx=s.find(part);
        if(idx==string::npos){
            return s;
        }
        else{
            s.erase(s.begin()+idx,s.begin()+idx+part.size());
        }
        // cout<<s<<endl;
       }
       return s;
    }
};
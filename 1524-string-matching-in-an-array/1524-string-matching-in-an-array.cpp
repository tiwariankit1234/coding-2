class Solution {
public:

bool check(string& s,string& t){
    if(t.find(s)!=string::npos){
        return true;
    }
    return false;
}
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                if(check(words[i],words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
         } 
        }
        return ans;
    }
};
class Solution {
public:
int n;
unordered_set<string>hashset;

string generate(string s){
     if(s.size()==n){
        if(hashset.find(s)==hashset.end()){
            return s;
        }
        else
        return "";
     }

     string t=generate(s+'0');
     if(t!="")return t;
      string z=generate(s+'1');
      return z;
}
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();

        for(auto it:nums){
            hashset.insert(it);
        }
        return generate("");
    }
};
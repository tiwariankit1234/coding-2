class Solution {
public:
    bool rotateString(string s, string t) {
        int n=s.size(),k=t.size();
        
        if(s==t)return true;
        for(int i=0;i<n;i++){
           rotate(s.begin(),s.begin()+1,s.end());
            if(s==t)return true;
        }

        return false;
        
    }
};
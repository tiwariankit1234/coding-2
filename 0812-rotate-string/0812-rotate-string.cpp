class Solution {
public:
    bool rotateString(string s, string t) {
        int n=s.size(),k=t.size();
        
        if(s==t)return true;
        for(int i=0;i<=n-2;i++){
            string z=s.substr(i+1);
            z+=s.substr(0,i+1);
            // cout<<z<<" " <<i<<endl;
            if(z==t)return true;
        }

        return false;
        
    }
};
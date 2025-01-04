class Solution {
public:
    string discountPrices(string sentence, int discount) {
        
        stringstream s(sentence);
        string word, ans = "";
        
        while(s >> word) {
            if(word[0] == '$' && word.size() > 1) {
                
                bool isNum = true;
                string s = "";
                
                for(int i = 1; i < word.size(); ++i) {
                    s += word[i];
                    if(!(word[i] >= '0' && word[i] <= '9')) {
                        isNum = false;
                        break;
                    }
                }
                
                if(isNum) {
                    
                    long double d = stoll(s) * (100-discount)/100.0+0.001;
                    string a = to_string(d), b = "";
                    
                    int f = 0, isDot = false;
                    
                    for(int i = 0; i < a.size() && f <= 2; ++i) {
                        if(a[i] == '.') isDot = true;
                        if(isDot) ++f;
                        b += a[i];
                    }
                    
                    ans += '$' + b + ' ';
                }
                else ans += word + ' ';
                
            }
            else ans += word + ' ';
        }
        
        return ans.substr(0,ans.size()-1);
    }
};
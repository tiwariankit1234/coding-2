class Solution {
public:
    int minimumOperations(string num) {
        int n=num.size();
 
            
        set<char>s;
        bool zerofound=false;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0'){
                if(s.contains('0'))
                return (n-i-2);
                else{
                    s.insert(num[i]);
                }
                zerofound=true;
            }

             else if(num[i]=='5'){
                if(s.contains('0'))
                return (n-i-2);
                else{
                    s.insert(num[i]);
                }
            }

             else if(num[i]=='2'){
                if(s.contains('5'))
                return (n-i-2);
                else{
                    s.insert(num[i]);
                }
            }

            else if(num[i]=='7'){
                if(s.contains('5'))
                return (n-i-2);
                else{
                    s.insert(num[i]);
                }
            }
        }
       if(zerofound)return (n-1);
       return n;
    }
};
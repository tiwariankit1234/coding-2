class Solution {
public:
    int numSteps(string s) {
        string newstring="";
        int count=0;
        while(s.size()!=1){
          int k=s.size();
          newstring="";
          if(s[k-1]=='1'){
            bool flag=false;
            for(int i=k-1;i>=0;i--){
                if(s[i]=='0'){
                    s[i]='1';
                    flag=true;
                    break;
                }
                else{
                    s[i]='0';
                }

            }
            if(!flag){
                newstring+='1';
                newstring+=s;
                s=newstring;
            }
            count++;
          }
          else{
            for(int i=0;i<k-1;i++){
                newstring+=s[i];
            }
            s=newstring;
            count++;
          }
        }
        return count;
    }
};
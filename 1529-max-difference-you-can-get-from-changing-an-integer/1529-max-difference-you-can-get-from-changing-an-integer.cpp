class Solution {
public:
    int maxDiff(int num) {
       
        string s=to_string(num);
         int n=s.size();
        char ch1;
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
               ch1=s[i];
               break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]==ch1){
                s[i]='9';
            }
        }
        int maxi=stoi(s);
        int mini;
        string t=to_string(num);
        // sabko one karenge 
        if(t[0]!='1'){
            char ch2=t[0];
            for(int i=0;i<n;i++){
                if(t[i]==ch2){
                    t[i]='1';
                }
            }
          
        }
        // sabko zero karege
        else{
            char ch2;
            int count=0;
            for(int i=0;i<n;i++){
                if(t[i]=='1'){
                   count++;
                }
            }
            if(count==t.size()){
                return maxi-stoi(t);
            }
            for(int i=0;i<n;i++){
                if(t[i]!='1' and t[i]!='0'){
                ch2=t[i];
                break;
                }
            }
            for(int i=0;i<n;i++){
                if(t[i]==ch2){
                    t[i]='0';
                }
            }
        }
        mini=stoi(t);
        cout<<maxi<<" "<<mini<<endl;
        return maxi-mini;
    }
};
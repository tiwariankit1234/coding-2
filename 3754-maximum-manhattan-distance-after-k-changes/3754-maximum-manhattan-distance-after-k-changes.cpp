class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
         map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        char minchar;
        if(mp['N']>mp['S']){
            minchar='S';
        }
        else if(mp['N']<mp['S']){
             minchar='N';
        }
        
        for(int i=0;i<n;i++){
            if(k>0){
            if(s[i]==minchar){
                if(s[i]=='N'){
                    s[i]='S';
                }
                else{
                    s[i]='N';
                }
                k--;
            }
              
        }
    }


        // cout<<k<<endl;
        if(mp['W']>mp['E']){
            minchar='E';
        }
        else if(mp['W']<mp['E']){
             minchar='W';
        }

                for(int i=0;i<n;i++){
            if(k>0){
            if(s[i]==minchar){
                if(s[i]=='W'){
                    s[i]='E';
                }
                else{
                    s[i]='W';
                }
                k--;
            }
               
        }
    }
         for(auto it:s){
             cout<<it<<" ";
         }
        int maxdist=0,dist=0;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                 y++;
            }
            else if(s[i]=='W'){
                x--;
            }
            else if(s[i]=='E'){
                x++;
            }
            else if(s[i]=='S'){
                y--;
            }
            maxdist=max(maxdist,abs(x)+abs(y));
        }
        return maxdist;

    }

        
        

        
};
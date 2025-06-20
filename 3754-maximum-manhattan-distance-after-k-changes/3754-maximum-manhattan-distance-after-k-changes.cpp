class Solution {
public:
int f(string &t){
    int distance=0,maxdistance=0,x=0,y=0;
    int n=t.size();
    for(int i=0;i<n;i++){
        if(t[i]=='N'){
          y++;
        }
        else if(t[i]=='S'){
            y--;
        }
        else if(t[i]=='W'){
            x--;
        }
        else{
            x++;
        }
        maxdistance=max(maxdistance,abs(x)+abs(y));
    }
    return maxdistance;
}
    int maxDistance(string s, int k) {
        int n=s.size(),maxdistance=INT_MIN;
        string t=s;
        int m=k;
        // NW  
        for(int i=0;i<n;i++){
             if(t[i]=='S'){
               if(m>0){
                t[i]='N';
                m--;
               }
             }
             else if(t[i]=='E'){
                if(m>0){
                    t[i]='W';
                    m--;
                }
             }
        }
        maxdistance=max(maxdistance,f(t));
        m=k,t=s;
        //NE

        for(int i=0;i<n;i++){
             if(t[i]=='S'){
               if(m>0){
                t[i]='N';
                m--;
               }
             }
             else if(t[i]=='W'){
                if(m>0){
                    t[i]='E';
                    m--;
                }
             }
        }
        maxdistance=max(maxdistance,f(t));
        m=k,t=s;
        //SW

         for(int i=0;i<n;i++){
             if(t[i]=='N'){
               if(m>0){
                t[i]='S';
                m--;
               }
             }
             else if(t[i]=='E'){
                if(m>0){
                    t[i]='W';
                    m--;
                }
             }
        }
        maxdistance=max(maxdistance,f(t));
        m=k,t=s;

        // SE

         for(int i=0;i<n;i++){
             if(t[i]=='N'){
               if(m>0){
                t[i]='S';
                m--;
               }
             }
             else if(t[i]=='W'){
                if(m>0){
                    t[i]='E';
                    m--;
                }
             }
        }
        maxdistance=max(maxdistance,f(t));
        m=k,t=s;
         return  maxdistance;


    }
};
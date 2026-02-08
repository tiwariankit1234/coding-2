class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //har ek zero ke pehle kitne one hain and 
        // aur uske baad kitne zero hain
        int leftzero=0,leftone=0,totalzero=0,totalone=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')totalone+=1;
            else{
                totalzero+=1;
            }
        }

        int minflips=INT_MAX;
        minflips=min(minflips,totalone);
        minflips=min(minflips,totalzero);
                for(int i=0;i<n;i++){
            if(s[i]=='1'){
                minflips=min(minflips,leftone+totalzero-leftzero);
                leftone++;
            }
            else{
                minflips=min(minflips,leftone+totalzero-leftzero);
                leftzero++;
            }
        }
        return minflips;
    }
};
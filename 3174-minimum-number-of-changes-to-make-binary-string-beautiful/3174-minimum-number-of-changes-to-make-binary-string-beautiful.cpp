class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int i=0,j=0,changes=0;
        int zerocount=0,onecount=0;
        while(i<n-1){
            onecount=0;
            zerocount=0;
            j=0;
            while(j<2){
                if(s[i+j]=='1'){
                     onecount++;
                }
                else{
                  
                    zerocount++;
                }
               j++;
            }

            if(zerocount==1 and onecount==1)changes+=1;
            i+=j;

            cout<<i<<" "<<endl;
        }
        return changes;
    }
};
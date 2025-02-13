class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        int index=-1;
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
            index=i;
           break;
            }
        }
        if(index==-1){
            s[n-1]='z';
            return s;
        }
        for(int j=index;j<n;j++){
            if(s[j]!='a'){
                s[j]--;
            }
            else{
                break;
            }
        }
        return s;
    }
};
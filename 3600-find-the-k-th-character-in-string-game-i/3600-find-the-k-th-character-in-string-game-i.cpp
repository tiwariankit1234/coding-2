class Solution {
public:
    char kthCharacter(int k) {
        int n=log2(k)+1;
        string originalstring="a";
        if(k==1)return 'a';

        while(n>0){
           string newstring="";
           for(int i=0;i<originalstring.size();i++){
            char ch=originalstring[i];
            ch++;
            newstring+=ch;
           }
           originalstring+=newstring;
           n--;
        }

        return originalstring[k-1];

        
    }
};
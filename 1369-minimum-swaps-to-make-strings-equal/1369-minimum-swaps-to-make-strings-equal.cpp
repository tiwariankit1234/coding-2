class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.size();
        int countx=0,county=0;
        if(s1==s2)return 0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x')
                countx++;
                else
                county++;
            }
        }
        //   if(countx==1 and county%2==0|| county==1 and countx%2==0)return -1;
        if ((countx + county) % 2 != 0) return -1;

        return countx/2+county/2+2*(countx%2);
    }
};
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int size=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                size++;
            }
            else{
                if(k-pow(2,size)>=0){
                    k=k-pow(2,size);
                    size++;
                    
                }
            }
        }
        return size;
    }
};
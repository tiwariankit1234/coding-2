class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int score=0;
        int totalone=0,leftzero=0,leftone=0;
        for(auto it:s){
            if(it=='1')
            totalone++;
        }
        cout<<totalone<<endl;
        for(int i=0;i<(n-1);i++){
            if(s[i]=='0'){
                leftzero++;
            }
            else if(s[i]=='1'){
               totalone--;
            }
           score=max(score,leftzero+totalone);
        }
        return score;
    }
};
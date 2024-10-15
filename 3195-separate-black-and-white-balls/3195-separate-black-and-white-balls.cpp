class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
       long long countone=0;
        long long  swap=0;

        // 0 ke pehle kitne 1 hain vo count karo 
        // aur jab 0 aaye toh swap me add kar do
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                countone++;
            }
            else{
                swap+=countone;
            }
        }
        return swap;
    }
};
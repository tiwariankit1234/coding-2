class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        for(char ch:text){
            freq[ch-'a']++;
        }
        freq['l'-'a']/=2;
        freq['o'-'a']/=2;
        int minfreq=INT_MAX;
        minfreq=min(minfreq,freq['b'-'a']);
        minfreq=min(minfreq,freq['a'-'a']);
        minfreq=min(minfreq,freq['l'-'a']);
        minfreq=min(minfreq,freq['o'-'a']);
        return minfreq;
    }
};
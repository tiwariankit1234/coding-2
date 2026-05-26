class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size(),count=0;
        unordered_set<int>st(word.begin(),word.end());
        for(char ch:st){
            if(st.find(ch+32)!=st.end()){
                count++;
            }
        }
        return count;
       
    }
};
//https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02


// mistake 

//use break statement 

// comparison two strings use two pointers 
class Solution {
public:


bool check(string &stringwords,string &t){
    int i=0,j=0;
    int n=stringwords.size();
    int k=t.size();
    if(k>n)return false;
    while(j<k){
        if(stringwords[i++]!=t[j++])
        return false;    
    }
    return true;
}
    int isPrefixOfWord(string sentence, string searchWord) {
    stringstream ss(sentence); // To split the sentence into words
        vector<string>stringwords;
        string word;

        // Split the sentence into words and store in `stringWords`
        while (ss >> word) {
            stringwords.push_back(word);
        }

        int n=stringwords.size();
        int minindex=-1;
        for(int i=0;i<n;i++){
            string k=stringwords[i];

         if(check(k,searchWord)){
             minindex=i+1;
             break;
         }
        
        }

        return minindex;
    }
};
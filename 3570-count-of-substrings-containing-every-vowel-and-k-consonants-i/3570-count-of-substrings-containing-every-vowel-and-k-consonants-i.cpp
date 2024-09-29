class Solution {
public:

  bool check(char ch){
    if(ch=='a' || ch=='e' ||ch=='i'||ch=='o'||ch=='u')
    return true;
    else
    return false;
 }

    int countOfSubstrings(string word, int k) {
        int n=word.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_set<char>vowels;
            int consonantcount=0;
            for(int j=i;j<n;j++){
                if(check(word[j])){
                    vowels.insert(word[j]);
                }
                else{
                     consonantcount++;
                }
            
            if(vowels.size()==5 and consonantcount==k){
                count++;
                
            }
            if(consonantcount>k)
            break;
        
        }
    }
    return count;
    }
};
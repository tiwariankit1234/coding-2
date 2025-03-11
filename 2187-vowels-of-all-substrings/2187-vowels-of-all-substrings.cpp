#define ll long long
class Solution {
public:
    long long countVowels(string word) {
        long long n=word.size();
        long long count=0;
        for(long long i=0;i<n;i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='o'||word[i]=='i'||word[i]=='u'){
            count+=(i)+(n-1-i)+1+i*(n-1-i);
            }
        }
        return count;
    }
};
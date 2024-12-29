class Solution {
public:
    string answerString(string word, int nf) {
        if(nf==1) return word;
        string largest = "";
        vector<int> v;
        int maxi = -1e9;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] - '0' > maxi) {
                maxi = word[i] - '0';
            }
        }
        int l = word.size() - nf + 1;

        string lar = "";
        cout<<maxi<<endl;
        int n=word.size();
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] - '0' == maxi) {
                string longest = "";
                for (int j = i; j < i + l&j<n; j++) {
                    longest += word[j];
                    lar = max(lar, longest);
                }
            }
        }
     

       

        return lar;
    }
};
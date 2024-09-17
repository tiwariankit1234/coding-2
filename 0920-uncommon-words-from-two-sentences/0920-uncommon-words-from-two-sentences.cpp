class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>wordcount;
        string word;

        stringstream data1(s1);
        while(data1 >> word){
            wordcount[word]++;
        }

        stringstream data2(s2);
        while(data2>>word){
            wordcount[word]++;
        }

        vector<string>result;

        for(auto& entry:wordcount){
            if(entry.second==1){
                result.push_back(entry.first);
            }
        }
        return result;
    }

};
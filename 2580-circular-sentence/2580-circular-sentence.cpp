class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string s;
       vector<string>ans;

        while(ss>>s){
            ans.push_back(s);
        }
       
       int n=ans.size();
        for(int i=1;i<n;i++){
           string currentstring=ans[i];
           string previousstring=ans[i-1];

           if(currentstring[0]!=previousstring[previousstring.size()-1])
           return false;


        }

        string laststring=ans[ans.size()-1];
        string firststring=ans[0];

        if(firststring[0]!=laststring[laststring.size()-1])
        return false;

        return true;

    }
};
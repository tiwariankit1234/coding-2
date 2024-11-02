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


         if(ans[0].front()!=ans[ans.size()-1].back())
        return false;


       char last=ans[0].back();
        for(int i=1;i<n;i++){
           
          if(ans[i].front()!=last)return false;
  
         last=ans[i].back();

        }

        if(ans[0].front()!=ans[ans.size()-1].back())
        return false;

        return true;

    }
};
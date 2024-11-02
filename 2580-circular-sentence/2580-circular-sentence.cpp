// use of front and last character 

class Solution {
// public:
//     // bool isCircularSentence(string sentence) {
//     // //     stringstream ss(sentence);
//     // //     string s;
//     // //    vector<string>ans;

//     // //     while(ss>>s){
//     // //         ans.push_back(s);
//     // //     }


       
//     // //    int n=ans.size();


//     // //      if(ans[0].front()!=ans[ans.size()-1].back())
//     // //     return false;


//     // //    char last=ans[0].back();
//     // //     for(int i=1;i<n;i++){
           
//     // //       if(ans[i].front()!=last)return false;
  
//     // //      last=ans[i].back();

//     // //     }

//     // //     if(ans[0].front()!=ans[ans.size()-1].back())
//     // //     return false;

//     // //     return true;

//     // }

public:
      bool isCircularSentence(string s){
        int n=s.size();
        
        if(s[0]!=s[n-1])return false;

        for(int i=0;i<n;i++){
            if(s[i]==' ' and s[i-1]!=s[i+1])
            return false;
        }
         
         return true;
      }
};
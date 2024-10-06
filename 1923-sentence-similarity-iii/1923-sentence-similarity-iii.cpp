class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();

        deque<string>dq1,dq2;
            
            string s="";
        for(int i=0;i<m;i++){
         if(s1[i]!=' ')
            s+=s1[i];
         
         else{
            dq1.push_back(s);
            s="";
         }
    }  
    dq1.push_back(s);
        
        
          s="";
        for(int i=0;i<n;i++){
         if(s2[i]!=' ')
            s+=s2[i];
         
         else{
            dq2.push_back(s);
            s="";
         }
    }  

    dq2.push_back(s);

    // for(auto it:s1)
    // cout<<it<<" ";

    // cout<<endl;

    //  for(auto it:s2)
    // cout<<it<<" ";

  

          
               cout<<dq1.size()<<" "<<dq2.size()<<endl;

         // see the front
         while(dq1.size() and dq2.size()){
            string first=dq1.front();
            string second=dq2.front();
            if(first!=second)break;
            else
            {
               
                dq1.pop_front();
                dq2.pop_front();
            }
         }
             
               cout<<dq1.size()<<" "<<dq2.size()<<endl;
          // see the back
            while(dq1.size() and dq2.size()){
            string first=dq1.back();
            string second=dq2.back();
            if(first!=second)break;
            else
            {
                dq1.pop_back();
                dq2.pop_back();
            }
         }

        //  cout<<dq1.size()<<" "<<dq2.size()<<endl;

         return (dq1.empty() || dq2.empty());


    }
};
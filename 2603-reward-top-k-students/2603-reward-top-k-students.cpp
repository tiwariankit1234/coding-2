class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string>posfeed(positive_feedback.begin(),positive_feedback.end()),negfeed(negative_feedback.begin(),negative_feedback.end());
          vector<int>score;
          int n=student_id.size();
        for(auto it:report){
            int ans=0;
           stringstream ss(it);
           string s;
           while(ss>>s){
            if(posfeed.count(s)){
               ans+=3;
            }
            else if(negfeed.count(s)){
                ans-=1;
            }
           }
           score.push_back(ans);

        }

        vector<pair<int,int>>scoreid;

        for(int i=0;i<n;i++)
            scoreid.push_back({score[i],student_id[i]});

            sort(scoreid.begin(),scoreid.end(),[](const pair<int,int>&a,const pair<int,int>&b) {
                if(a.first!=b.first)
                return a.first>b.first;
                
                return a.second<b.second;
            });

            vector<int>finalarray;
            for(int i=0;i<k;i++){
                finalarray.push_back(scoreid[i].second);
            }

        return finalarray;
    }
};
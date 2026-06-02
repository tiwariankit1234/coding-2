class Solution {
public:
    int earliestFinishTime(vector<int>& first, vector<int>& second, vector<int>& third, vector<int>& fourth) {
        int n=first.size(),m=third.size();
        int minitime=INT_MAX;
        for(int i=0;i<n;i++){
            int time=first[i]+second[i];
            int k=INT_MAX;
            for(int j=0;j<m;j++){
                k=min(k,max(time,third[j])+fourth[j]);
            }
          
               minitime=min(minitime,k);
             // cout<<i<<" "<<time<<" "<<k<<" "<<minitime<<endl;
        }
        // cout<<"outer"<<endl;
        // cout<<minitime<<" "<<endl;
          for(int i=0;i<m;i++){
            int time=third[i]+fourth[i];
            int k=INT_MAX;
            for(int j=0;j<n;j++){
                k=min(k,max(time,first[j])+second[j]);
            }
            minitime=min(minitime,k);
         // cout<<i<<" "<<time<<" "<<k<<" "<<minitime<<endl;
        }
        // cout<<" outer"<<endl;
        //      cout<<minitime<<" "<<endl;
        return minitime;
        
    }
};
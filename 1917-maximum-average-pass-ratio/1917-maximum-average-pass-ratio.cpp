class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        priority_queue<pair<double,int>>pq;
        double n=classes.size();
        // cout<<double(5)/2<<endl;
        vector<double>delta(classes.size(),0);
        int i=0;
        for(auto it:classes){
delta[i++] = ((double)(it[0] + 1) / (it[1] + 1)) - ((double)it[0] / it[1]);

        }
         int idx=0;
        for(auto it:delta){
          pq.push({delta[idx],idx});
          idx++;
        }
    
         double diff;
        while(k--){
            auto [diff,idx]=pq.top();
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
    double newdelta = ((double)(classes[idx][0] + 1) / (classes[idx][1] + 1)) - ((double)classes[idx][0] / classes[idx][1]);

            pq.push({newdelta,idx});
        }

        double avg=0;
        for(auto it:classes){
            avg+=double(it[0])/it[1];
        }
        return avg/n;
         
    }
};
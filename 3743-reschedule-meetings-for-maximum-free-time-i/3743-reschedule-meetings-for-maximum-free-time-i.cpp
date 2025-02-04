class Solution {
public:
    int maxFreeTime(int eventime, int k, vector<int>& startime, vector<int>& endtime) {
        k++;
        int n=startime.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({startime[i],endtime[i]});
        }
        vector<int>gap;
        int lastime=0;
        for(int i=0;i<n;i++){
            int start=v[i].first;
            int end=v[i].second;
            if(start>=lastime){
               gap.push_back(start-lastime);
            }
            lastime=end;
        }
        if(eventime>=lastime)gap.push_back(eventime-lastime);
        int l=0,r=0,t=gap.size();
        int sum=0,maxsum=0;
        while(r<t){
          sum+=gap[r];
          if((r-l+1)>k){
            sum-=gap[l];
            l++;
          }
         maxsum=max(sum,maxsum);
          r++;
        }
        return maxsum;
    

    }
};
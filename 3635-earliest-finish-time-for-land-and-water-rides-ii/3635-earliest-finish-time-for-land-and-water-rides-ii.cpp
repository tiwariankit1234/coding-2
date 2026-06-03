class Solution {
public:
    int earliestFinishTime(vector<int>& landstart, vector<int>& landend, vector<int>& waterstart, vector<int>& waterend) {
        int k=landstart.size();
           vector<int>startlandtime(k);
        for(int i=0;i<k;i++){
          startlandtime[i]=landstart[i]+landend[i];
        }
        sort(startlandtime.begin(),startlandtime.end());
        int m=waterstart.size();
        vector<int>startwatertime(m);
        for(int i=0;i<m;i++){
            startwatertime[i]=waterstart[i]+waterend[i];
        }
        sort(startwatertime.begin(),startwatertime.end());
        int mintime=INT_MAX;
        // landwater
        for(int i=0;i<m;i++){
            mintime=min(mintime,max(waterstart[i],startlandtime[0])+waterend[i]);
        }
        for(int i=0;i<k;i++){
            mintime=min(mintime,max(startwatertime[0],landstart[i])+landend[i]);
        }
        return mintime;
    }
};
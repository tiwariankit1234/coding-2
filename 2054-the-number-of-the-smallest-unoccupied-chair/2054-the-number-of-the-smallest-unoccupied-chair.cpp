class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<int>targettime=times[targetFriend];
        sort(times.begin(),times.end());

        vector<int>chairtime(times.size(),0);

        for(int i=0;i<n;i++){

            int startime=times[i][0];
            int endtime=times[i][1];

            for(int i=0;i<chairtime.size();i++){
                if(startime>=chairtime[i]){
                    chairtime[i]=endtime;
                    if(startime==targettime[0] and endtime==targettime[1]){
                        return i;
                    }
                    break;
                }
            }

        }

    return -1;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         
        vector<int>maxline(1002,0);
        for(auto it:trips){
            int pass=it[0];
            int start=it[1];
            int end=it[2];
            maxline[start]+=pass;
            maxline[end]-=pass;
        }

        int givencapacity=0;
        for(int i=0;i<1002;i++){
            givencapacity+=maxline[i];
            if(givencapacity>capacity)
            return false;
        }
        return true;
    }
};
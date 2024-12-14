class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       
        sort(points.begin(),points.end());
        int minend=INT_MAX;
        int count=1;
        for(auto it:points){
            if(it[0]>minend){  // overlapping condition update minend key parameter of the overlapping set 
                count++;
                minend=it[1]; 
            }
            else{
                 minend=min(minend,it[1]);                          //agar nahi toh update the new state of overlapping set          
            } 
        }
        return count;
    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentheight=0,maxheight=0;
        for(auto it:gain){
            maxheight=max(maxheight,currentheight);
            currentheight+=it;
             cout<<currentheight<<endl;
        }
        maxheight=max(maxheight,currentheight);
        return maxheight;
    }
};
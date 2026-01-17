#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& botl, vector<vector<int>>& topr) {
        ll ans=0;
        ll n=botl.size();
        ll side=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll minx=max(botl[j][0],botl[i][0]);
                ll miny=max(botl[j][1],botl[i][1]);
                ll maxx=min(topr[i][0],topr[j][0]);
                ll maxy=min(topr[i][1],topr[j][1]);
                if((maxx-minx)>0 and (maxy-miny)>0)
                side=max(side,min((maxx-minx),(maxy-miny)));
            }
        }
        return side*side;
    }
};
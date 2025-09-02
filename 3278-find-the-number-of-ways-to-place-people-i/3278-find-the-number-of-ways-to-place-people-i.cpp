class Solution {
public:
bool check(int i,int j,vector<vector<int>>& points){
    
    int x=points[i][0],y=points[i][1],m=points[j][0],n=points[j][1];
    if(!(x<=m and y>=n))return false;
    for(int k=i+1;k<j;k++){
        int p=points[k][0],q=points[k][1];
        if(x<=p and p<=m and n<=q and q<=y){
            return false;
        }
    }
    return true;
}
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int n=points.size(),count=0;
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            for(int j=i+1;j<n;j++){
                if(check(i,j,points)){
                  count++;
                }
            }
        }
        return count;
    }
};
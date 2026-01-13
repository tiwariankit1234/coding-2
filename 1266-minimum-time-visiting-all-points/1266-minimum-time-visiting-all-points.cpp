class Solution {
public:
int f(vector<int>&a,vector<int>&b){
    int x=a[0],y=a[1],z=b[0],w=b[1];
     int x1=INT_MAX;
     if(x==z  and y==w){
        return x1=0;
     }
     if(x==z){
        return abs(y-w);
     }
     if(y==w){
        return abs(x-z);
     }
     int x2=abs(x-z);
     int x3=abs(y-w);
     if(x2>=x3){
        return x3+min(abs(x+x3-z),abs(x-x3-z));
     }
     else{
        return x2+min(abs(y+x2-w),abs(y-x2-w));
     }
}
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size(),sum=0;
        for(int i=0;i<(n-1);i++){
            sum+=f(points[i],points[i+1]);
        }
        return sum;
    }
};
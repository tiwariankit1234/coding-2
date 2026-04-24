class Solution {
public:
int ans=INT_MIN;
pair<int,int> f(int idx,string& moves){
    int n=moves.size();
    if(idx==n)return {0,0};
    

    if(moves[idx]=='_'){
     auto[x,y]=f(idx+1,moves);
     
     int mini=min(x-1,y-1);
     int maxi=max(x+1,y+1);
    //  ans=max(abs(mini),abs(maxi));
     cout<<idx<<" "<<x<<" "<<y<<endl;
     return {mini,maxi};
    }
    else if (moves[idx]=='L'){
      auto[x,y]=f(idx+1,moves);
    //   ans=max(ans,abs(x-1));
    //   ans=max(ans,abs(y-1));
      cout<<idx<<" "<<x<<" "<<y<<endl;
      return {x-1,y-1};
    }
    else{
        auto [x,y]=f(idx+1,moves);
        //  ans=max(ans,abs(x+1));
        //  ans=max(ans,abs(y+1));
         cout<<idx<<" "<<x<<" "<<y<<endl;
         return {x+1,y+1};
    }
}
    int furthestDistanceFromOrigin(string moves) {
      auto [x,y]=f(0,moves);
      ans=max(abs(x),abs(y));
      return ans;
    }
};
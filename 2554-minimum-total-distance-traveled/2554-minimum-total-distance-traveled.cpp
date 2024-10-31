#define ll long long 
ll dp[103][10000];
class Solution {
public:
    vector<int>newfactory;
       vector<int>newrobot;
     
     
     ll f(int robotidx,int factoryidx){
     
     
     if(robotidx<0)return 0;
     
     if(factoryidx<0)return 1e12;
      
    if(dp[robotidx][factoryidx]!=-1)return dp[robotidx][factoryidx];      

        // take
       ll ans1=(abs)(newrobot[robotidx]-newfactory[factoryidx])+f(robotidx-1,factoryidx-1);
        // not take
       ll ans2=f(robotidx,factoryidx-1);
        return dp[robotidx][factoryidx]= min(ans1,ans2);

     }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
          newrobot=robot;
        sort(newrobot.begin(),newrobot.end());
        
       memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<factory.size();i++){
            int frequency=factory[i][1];
            while(frequency>0){
                newfactory.push_back(factory[i][0]);
                frequency--;
            }
        }
       

        sort(newfactory.begin(),newfactory.end());
        // for(auto it:newfactory)
        // cout<<it<<" ";

        // cout<<endl;

        // cout<<robot.size()-1<<" "<<newfactory.size()-1<<endl;
        return f(robot.size()-1,newfactory.size()-1);
    }
};
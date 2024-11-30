class Solution {
public:
	

    int findChampion(int k, vector<vector<int>>& grid) {
          vector<int>indegree(k,0);
          for(int i=0;i<grid.size();i++){
            indegree[grid[i][1]]++;
          }
          int champion=-1;
          for(auto it:indegree)
          cout<<it<<" ";

          cout<<endl;
          for(int i=0;i<indegree.size();i++){
           if(indegree[i]==0){
            if(champion==-1)
            champion=i;
            else
            return -1;
        
           }
          }

    

    return champion;



    }
};
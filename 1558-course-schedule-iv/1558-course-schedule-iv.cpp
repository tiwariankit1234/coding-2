class Solution {
public:

int topoSort(int v, vector<vector<int>>&adj,int start,int end) 
	{
	   vector<int>visited(v,0);
	    queue<int>q;
	    q.push(start);
	     visited[start]=1;
	     while(q.size()>0){
	         int node=q.front();
	         q.pop();

             if(node==end)return true;
	       
	         
	         // node is in topo
	         // so please remove it from the indegree
	         for(auto it:adj[node] ){
                if(visited[it]==0){
	             q.push(it);
                 visited[it]=1;
                }
	         }   
	     }
	       return false;
	}



    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
           int v=numCourses;
        int m=prerequisites.size();
        
        vector<vector<int>>adj(v);
       for(auto it:prerequisites){
        int prerequisites=it[0];
        int course=it[1];
     
        adj[prerequisites].push_back(course);   
    }
   
    vector<bool>ans(queries.size(),false);
    if(prerequisites.size()==0)return ans;
        int i=0;
    for(auto it:queries){
        ans[i++]=topoSort(v,adj,it[0],it[1]);
    }
    
    return ans;
    }
};
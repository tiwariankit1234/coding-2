class Solution {
public:

 int topoSort(int V, vector<int> adj[],string &color)
	{
        int maxi=INT_MIN;
        vector<int>indegree(V,0);
        vector<vector<int>>cnt(V,vector<int>(26,0));
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}
          
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
                cnt[i][color[i]-'a']=1;
			}
		}

		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
            int temp=*max_element(cnt[node].begin(),cnt[node].end());
            maxi=max(maxi,temp);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
                for(int j=0;j<26;j++){
                    cnt[it][j]=max(cnt[it][j],cnt[node][j]);
                }
                 cnt[it][color[it] - 'a'] = max(cnt[it][color[it] - 'a'], cnt[node][color[it] - 'a'] + 1);
				if (indegree[it] == 0) q.push(it);
			}
		}

		if(topo.size()<V)return -1;
        return maxi;
	}


    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int>adj[n];
        for(auto it:edges)
        adj[it[0]].push_back(it[1]);
        
       return topoSort(n,adj,colors);
       // This correctly checks for a cycle
         
       
    }
};
class Solution {
public:
    vector<vector<int>> graph;
    long long maxScore = 0;
    int root = -1;
    int maxScoreFrequency = 0;

    int dfs(int node) {
        int count = 0;
        long long score = 1;
        for(auto adj: graph[node]){
            auto child = dfs(adj);
            count += child;
            score *= child;
        }
        if(node != root) score *= (graph.size() -(count + 1));
        if(maxScore < score) {
            maxScore = score;
            maxScoreFrequency = 1;
        } else if(maxScore == score) {
            maxScoreFrequency++;
        }
        return count +1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        graph.resize(parents.size());
        for(int i = 0 ; i < parents.size(); i++) {
            if(parents[i] != -1) {
                graph[parents[i]].push_back(i);
            }else {
                root = i;
            }
        }
        dfs(root);
        return maxScoreFrequency;
    }
};
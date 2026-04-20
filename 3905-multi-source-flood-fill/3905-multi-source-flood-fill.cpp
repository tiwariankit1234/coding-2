class Node {
public:
    int steps;
    int row;
    int col;
    int val;
    Node(int steps, int row, int col, int val) {
        this->steps = steps;
        this->row = row;
        this->col = col;
        this->val = val;
    }
};
class Compare {
public:
    bool operator()(Node a, Node b) { return a.steps > b.steps; }
};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
    vector<vector<int>> colorGrid(int m, int n, vector<vector<int>>& sources) {
        priority_queue<Node, vector<Node>, Compare> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>>ans(m,vector<int>(n,0));
        for (auto it : sources) {
            Node x(0,it[0],it[1],it[2]);
        
            dist[it[0]][it[1]] = 0;
            ans[it[0]][it[1]]=it[2];
            pq.push(x);
        }
        while (pq.size()) {
            auto temp= pq.top();
            int steps=temp.steps,row=temp.row,col=temp.col,val=temp.val;
            // cout<<steps<<" "<<row<<" "<<col<<" "<<val<<endl;
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int newrow = row + dir[k][0], newcol = col + dir[k][1];
                if (newrow < m and newcol < n and newrow>=0 and newcol>=0 and 
                    steps + 1 < dist[newrow][newcol]) {
                    dist[newrow][newcol] = steps + 1;
                    // cout<<newrow<<" "<<newcol<<endl;
                    ans[newrow][newcol] = val;
                    Node x(steps+1,newrow,newcol,val);
                  
                    pq.push(x);
                } else if (newrow < m and newcol < n and newrow>=0 and newcol>=0 and 
                           steps + 1 == dist[newrow][newcol] and
                           val > ans[newrow][newcol]) {
                    ans[newrow][newcol] = val;
                    Node x(steps+1,newrow,newcol,val);
                    
                    pq.push(x);
                }
            }
        }
        return ans;
    }
};
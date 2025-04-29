class Solution {
public:

class DSU {
public:
    vector<int> parent, rank, size;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);  // Initially, size of each component is 1
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;  // Already in the same set

        if (rank[px] < rank[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[py] = px;
            size[px] += size[py];
            rank[px]++;
        }
        return true;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};






    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        int k=nums.size();
        for(int i=1;i<k;i++){
            if(abs(nums[i]-nums[i-1])<=maxDiff)
            dsu.unite(i-1,i);
        }
        vector<bool>ans(queries.size());
        int i=0;
        for(auto it:queries){
            int first=it[0],second=it[1];
            if(dsu.parent[first]==dsu.parent[second])
            ans[i++]=true;
            else
            ans[i++]=false;
        }
        return ans;
    }
};
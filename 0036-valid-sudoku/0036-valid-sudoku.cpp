class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        map<int, unordered_set<char>> mp;
        for (int i = 0; i < m; i++) {
            unordered_set<char> st;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '.') {
                    if (st.find(grid[i][j]) == st.end()) {
                        st.insert(grid[i][j]);
                    } else {
                        return false;
                    }

                    if (mp[i / 3 + (j / 3) * 9].find(grid[i][j]) ==
                        mp[i / 3 + (j / 3) * 9].end()) {
                        mp[i / 3 + (j / 3) * 9].insert(grid[i][j]);
                    } else {
                        return false;
                    }
                }
            }
            unordered_set<char> temp;
            for (int j = 0; j < m; j++) {
                if (grid[j][i] != '.') {
                    if (temp.find(grid[j][i]) == temp.end()) {
                        temp.insert(grid[j][i]);
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
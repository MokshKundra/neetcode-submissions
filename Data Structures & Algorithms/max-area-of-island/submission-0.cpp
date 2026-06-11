class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) res = max(dfs(grid, i, j), res);
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0) return 0;

        if (grid[r][c] == 1){
            int ret  = 1;
            grid[r][c] = 0;
            ret = ret + dfs(grid, r - 1, c)
                      + dfs(grid, r, c - 1)
                      + dfs(grid, r + 1, c)
                      + dfs(grid, r, c + 1);
            return ret;
        }

        return 0;
    }
};
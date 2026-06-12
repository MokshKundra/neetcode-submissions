class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i  < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) grid[i][j] = -1;
                else if(grid[i][j] == 2) grid[i][j] = 0;
                else if(grid[i][j] == 1) grid[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i  < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) dfs(grid, i, j, 0);
            }
        }

        int res = 0;
        for (int i = 0; i  < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                res = max(res, grid[i][j]);
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int i){
        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0) return;

        if(grid[r][c] >= i){
            grid[r][c] = i;
            dfs(grid, r - 1, c, i + 1);
            dfs(grid, r, c - 1, i + 1);
            dfs(grid, r + 1, c, i + 1);
            dfs(grid, r, c + 1, i + 1);
        }

        return;
    }


};
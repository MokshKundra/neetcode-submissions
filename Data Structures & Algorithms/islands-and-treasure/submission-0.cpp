class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) dfs(grid, i, j, 0);
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int i){
        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0) return;

        if(grid[r][c] >= i){
            grid[r][c] = i;
            dfs(grid, r + 1, c, i + 1);
            dfs(grid, r, c + 1, i + 1);
            dfs(grid, r - 1, c, i + 1);
            dfs(grid, r, c - 1, i + 1);            
        }

        return;
    }
};

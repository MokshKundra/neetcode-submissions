class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int r = 0; r < m; r++) {
            dfs(heights, r, 0, pac);
            dfs(heights, r, n - 1, atl);
        }

        for (int c = 0; c < n; c++) {
            dfs(heights, 0, c, pac);
            dfs(heights, m - 1, c, atl);
        }

        vector<vector<int>> res;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights,
             int r,
             int c,
             vector<vector<bool>>& vis) {

        if (vis[r][c]) return;

        vis[r][c] = true;

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, vis);
            }
        }
    }
};
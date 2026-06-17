class Solution {
public:
    unordered_map<int, vector<int>> graph;

    bool dfs(int node, int parent, vector<bool>& vis) {
        vis[node] = true;

        for (int nei : graph[node]) {
            if (nei == parent) continue;

            if (vis[nei]) return false;

            if (!dfs(nei, node, vis))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        if (!dfs(0, -1, vis))
            return false;

        for (bool v : vis) {
            if (!v) return false;
        }

        return true;
    }
};
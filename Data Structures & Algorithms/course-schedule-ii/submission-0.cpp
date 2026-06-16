class Solution {
public:
    vector<vector<int>> graph;
    vector<int> state;
    vector<int> order;

    bool dfs(int node) {
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;

        state[node] = 1;

        for (int nxt : graph[node]) {
            if (!dfs(nxt))
                return false;
        }

        state[node] = 2;
        order.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        graph.resize(numCourses);
        state.assign(numCourses, 0);

        for (auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i))
                return {};
        }

        return order;
    }
};
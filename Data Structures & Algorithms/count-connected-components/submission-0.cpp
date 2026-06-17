class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& e : edges) {
            int r1 = find(parent, e[0]);
            int r2 = find(parent, e[1]);

            if (r1 != r2)
                parent[r2] = r1;
        }

        set<int> roots;
        for (int i = 0; i < n; i++)
            roots.insert(find(parent, i));

        return roots.size();
    }
};

class Solution {
   public:
    bool dfs(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (neighbor == parent) continue;

            if (visited[neighbor]) return true;

            if (dfs(neighbor, node, adjList, visited)) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adjList(n);
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        vector<bool> visited(n, false);

        if (dfs(0, -1, adjList, visited)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};

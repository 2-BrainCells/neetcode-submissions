class Solution {
   public:
    void dfs(vector<vector<int>>& adjList, vector<bool>& state, int node) {
        state[node] = true;
        for (auto neighbor : adjList[node]) {
            if (state[neighbor] == false) {
                dfs(adjList, state, neighbor);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vector<bool> state(n, false);
        int count = 0;
        for (int i = 0; i < n; i += 1) {
            if (state[i] == false) {
                dfs(adjList, state, i);
                count += 1;
            }
        }
        return count;
    }
};

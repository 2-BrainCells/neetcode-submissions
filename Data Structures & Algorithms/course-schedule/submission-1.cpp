
class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;
        if (state[node] == 2) return false;
        state[node] = 1;
        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, state)) {
                return true;
            }
        }
        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];

            adj[b].push_back(a);
        }
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) {
                    return false;
                }
            }
        }
        return true;
    }
};

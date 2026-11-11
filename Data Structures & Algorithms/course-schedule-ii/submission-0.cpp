class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& state, vector<int>& order) {
        if (state[node] == 1) return true;
        if (state[node] == 2) return false;
        state[node] = 1;
        for (auto adj : adjList[node]) {
            if(dfs(adj, adjList, state, order)) return true;
        }
        state[node] = 2;
        order.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> adjList(numCourses);
        for (auto prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];

            adjList[b].push_back(a);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adjList, state, order)) return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};

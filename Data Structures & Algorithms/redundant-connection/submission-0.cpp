
class Solution {
   public:
    bool checkCycle(int node, int destination, vector<vector<int>>& adjList, vector<int>& visited) {
        if (node == destination) return true;

        visited[node] = 1;

        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                if (checkCycle(neighbor, destination, adjList, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adjList(n + 1);
        vector<int> visited(n + 1, 0);

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];

            fill(visited.begin(), visited.end(), 0);

            if (checkCycle(a, b, adjList, visited)) {
                return edge;
            }

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        return {};
    }
};

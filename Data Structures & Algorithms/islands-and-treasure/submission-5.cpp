class Solution {
public:
    void findLands(vector<vector<int>>& grid,
                   queue<pair<int, int>>& treasures) {

        int rows = grid.size();
        int cols = grid[0].size();

        int directions[4][2] = {
            {1, 0},   // Down
            {-1, 0},  // Up
            {0, 1},   // Right
            {0, -1}   // Left
        };

        while (!treasures.empty()) {
            auto [i, j] = treasures.front();
            treasures.pop();

            for (auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni < 0 || ni >= rows ||
                    nj < 0 || nj >= cols)
                    continue;

                if (grid[ni][nj] != INT_MAX)
                    continue;

                grid[ni][nj] = grid[i][j] + 1;

                treasures.push({ni, nj});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        queue<pair<int, int>> treasures;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    treasures.push({i, j});
                }
            }
        }

        findLands(grid, treasures);
    }
};
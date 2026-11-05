
class Solution {
public:
    void findMinTime(vector<vector<int>>& grid,
                     queue<pair<int, int>>& rotten,
                     int& time) {

        int rows = grid.size();
        int cols = grid[0].size();

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!rotten.empty()) {
            int size = rotten.size();
            bool change = false;

            while (size--) {
                auto [i, j] = rotten.front();
                rotten.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols)
                        continue;

                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        rotten.push({nr, nc});
                        change = true;
                    }
                }
            }

            if (change) time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int time = 0;
        queue<pair<int, int>> rotten;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        findMinTime(grid, rotten, time);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};

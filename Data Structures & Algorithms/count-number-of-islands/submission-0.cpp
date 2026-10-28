class Solution {
   public:
    void islands(vector<vector<char>>& grid, vector<vector<bool>>& maps, int& islandCount, int i,
                 int j) {
        if (i >= grid.size() || i < 0) return;
        if (j >= grid[0].size() || j < 0) return;
        if (grid[i][j] == '0') return;
        if (grid[i][j] == '1' && maps[i][j] == false) {
            maps[i][j] = true;
            islands(grid, maps, islandCount, i + 1, j);
            islands(grid, maps, islandCount, i, j + 1);
            islands(grid, maps, islandCount, i - 1, j);
            islands(grid, maps, islandCount, i, j - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> maps(rows, vector<bool>(columns, false));
        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && maps[i][j] == false) islandCount += 1;
                islands(grid, maps, islandCount, i, j);
            }
        }
        return islandCount;
    }
};

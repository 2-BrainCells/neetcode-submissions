class Solution {
   public:
    int islandMaxArea(vector<vector<int>>& grid, vector<vector<bool>>& maps, int i, int j,
                      int& rows, int& columns) {
        if (i >= rows || i < 0) return 0;
        if (j >= columns || j < 0) return 0;
        if (grid[i][j] == 0 || maps[i][j] == true) return 0;

        maps[i][j] = true;

        int area = 1;

        area += islandMaxArea(grid, maps, i + 1, j, rows, columns);
        area += islandMaxArea(grid, maps, i, j + 1, rows, columns);
        area += islandMaxArea(grid, maps, i - 1, j, rows, columns);
        area += islandMaxArea(grid, maps, i, j - 1, rows, columns);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;

        int columns = grid[0].size();
        vector<vector<bool>> maps(rows, vector<bool>(columns, false));

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1 && maps[i][j] == false) {
                    int area = islandMaxArea(grid, maps, i, j, rows, columns);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
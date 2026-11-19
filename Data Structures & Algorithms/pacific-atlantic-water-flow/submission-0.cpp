class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& pacific, int rows, int columns) {
        if (pacific[i][j] == 1) return;

        pacific[i][j] = 1;

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newI = i + dr[k];
            int newJ = j + dc[k];

            if (newI >= rows || newI < 0) continue;
            if (newJ >= columns || newJ < 0) continue;

            if (heights[newI][newJ] >= heights[i][j]) {
                dfs(newI, newJ, heights, pacific, rows, columns);
            }
        }
    }
    void check(vector<vector<int>>& heights, vector<vector<int>>& pacific,
               vector<vector<int>>& atlantic, int rows, int columns) {
        // top row
        for (int j = 0; j < columns; j++) {
            dfs(0, j, heights, pacific, rows, columns);
        }

        // left column
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, pacific, rows, columns);
        }

        //bottom row
        for (int j = 0; j < columns; j++) {
            dfs(rows - 1, j, heights, atlantic, rows, columns);
        }

        // right row
        for (int i = 0; i < rows; i++) {
            dfs(i, columns - 1 , heights, atlantic, rows, columns);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();

        vector<vector<int>> flow;
        vector<vector<int>> pacific(rows, vector<int>(columns, 0));
        vector<vector<int>> atlantic(rows, vector<int>(columns, 0));

        check(heights, pacific, atlantic, rows, columns);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(atlantic[i][j] == 1 && pacific[i][j] == 1){
                    flow.push_back({i, j});
                }
            }
        }
        return flow;
    }
};

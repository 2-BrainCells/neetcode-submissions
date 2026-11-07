class Solution {
   public:
    void updateRegion(vector<vector<char>>& board, queue<pair<int, int>>& region) {
        int rows = board.size();
        int cols = board[0].size();

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!region.empty()) {
            auto [i, j] = region.front();
            region.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni < 0 || ni >= board.size()) continue;
                if (nj < 0 || nj >= board[0].size()) continue;

                if (board[ni][nj] == 'O') {
                    board[ni][nj] = '#';
                    region.push({ni, nj});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> region;
        if (board.size() - 1 == 0 && board[0].size() - 1 == 0) return;
        for (int i = 0; i < board.size(); i += board.size() - 1) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = '#';
                    region.push({i, j});
                }
            }
        }
        for (int j = 0; j < board[0].size(); j += board[0].size() - 1) {
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == 'O') {
                    board[i][j] = '#';
                    region.push({i, j});
                }
            }
        }
        updateRegion(board, region);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';

            }
        }
    }
};

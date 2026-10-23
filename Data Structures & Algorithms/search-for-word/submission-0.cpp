class Solution {
public:
    bool combinations(vector<vector<char>>& board, string& word,
                      int start, int i, int j) {

        if (start == word.size()) return true;

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        if (board[i][j] != word[start]) return false;

        char original = board[i][j];
        board[i][j] = '#';

        bool found =
            combinations(board, word, start + 1, i + 1, j) ||
            combinations(board, word, start + 1, i - 1, j) ||
            combinations(board, word, start + 1, i, j + 1) ||
            combinations(board, word, start + 1, i, j - 1);

        board[i][j] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (combinations(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
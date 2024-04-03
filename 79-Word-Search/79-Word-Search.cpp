class Solution {
public:
    bool search(int k, int i, int j, vector<vector<char>>& board,
                string& word) {
        if (k == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }

        bool ans = false;

        if (word[k] == board[i][j]) {
            board[i][j] = '#'; // it means this grid is visited

            ans = search(k + 1, i+1, j, board, word) ||
                  search(k + 1, i, j-1, board, word) ||
                  search(k + 1, i, j+1, board, word) ||
                  search(k + 1, i-1, j, board, word);

            board[i][j] = word[k];
        }

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = 0;

                if (board[i][j] == word[k]) {
                    if (search(k, i, j, board, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

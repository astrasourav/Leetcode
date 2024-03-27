class Solution {
public:

    int livcnt(vector<vector<int>>& board, int i, int j) {
        int r = board.size();//row
        int c = board[0].size();//col
        int live=0;

        //horizontal
        if (j-1>=0) {
            if (board[i][j-1] == 1 || board[i][j-1] == 3) {
                live++;
            }
        }

        if (j+1<c) {
            if (board[i][j+1] == 1 || board[i][j+1] == 3) {
                live++;
            }
        }

        //vertical
        if (i-1>=0) {
            if (board[i-1][j] == 1 || board[i-1][j] == 3) {
                live++;
            }
        }

        if (i+1<r) {
            if (board[i+1][j] == 1 || board[i+1][j] == 3) {
                live++;
            }
        }

        //diagonal
        if (i-1>=0 && j-1>=0) {
            if (board[i-1][j-1] == 1 || board[i-1][j-1] == 3) {
                live++;
            }
        }

        if (i-1>=0 && j+1<c) {
            if (board[i-1][j+1] == 1 || board[i-1][j+1] == 3) {
                live++;
            }
        }

        if (i+1<r && j-1>=0) {
            if (board[i+1][j-1] == 1 || board[i+1][j-1] == 3) {
                live++;
            }
        }

        if (i+1<r && j+1<c) {
            if (board[i+1][j+1] == 1 || board[i+1][j+1] == 3) {
                live++;
            }
        }

        return live;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();//row
        int c = board[0].size();//col

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                int live = livcnt(board, i,j);

                if (board[i][j] == 0) {
                    if (live == 3) {
                        board[i][j] = 2;//2 means it will become live or 1
                    }
                } else if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = 3;//3 means it will become dead or 0
                    }
                }
            }
        }

        //For converting into new board;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};

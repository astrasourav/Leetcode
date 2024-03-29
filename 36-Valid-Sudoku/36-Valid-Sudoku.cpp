class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char val = board[i][j];

                if (val != '.') {
                    string row = "row"+to_string(i)+val;
                    string col = "col"+to_string(j)+val;
                    string subbox = "subbox"+to_string((i/3)*3 +(j/3))+val;

                    if (seen.find(row)==seen.end() && seen.find(col)==seen.end() && seen.find(subbox)==seen.end()) {
                        seen.insert(row);
                        seen.insert(col);
                        seen.insert(subbox);
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

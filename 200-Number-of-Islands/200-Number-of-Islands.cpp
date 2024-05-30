class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>>q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int dr = q.front().first;
            int dc = q.front().second;
            q.pop();

            for (int drow=-1; drow<=1; drow++) {
                for (int dcol = -1; dcol<=1; dcol++) {
                    int tr = dr+drow;
                    int tc = dc+dcol;

                    if (tr>=0 && tr< n && dcol>=0 && dcol<m && !vis[tr][tc] && grid[tr][tc] == '1') {
                        vis[tr][tc] = 1;
                        q.push({tr, tc});
                    } 
                }
            }
        }


    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();//row
        int m = grid[0].size();//col

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j <m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

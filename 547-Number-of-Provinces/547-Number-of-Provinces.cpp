class Solution {
public:
    void dfs (int node, vector<vector<int>>& isConnected, vector<int>& vis, int n) {
        for (int i=0; i<n; i++) {
            if (!vis[i] && isConnected[node][i]) {
                vis[i] = 1;
                dfs(i, isConnected, vis, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, isConnected, vis, n);
                ans++;
            }
        }

        return ans;
    }
};

class Solution {
  private:
    void dfs(int node, int vis[], vector<int> adj[], vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        
        for(auto it: adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, ls);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        
        dfs(start, vis, adj, ls);
        return ls;
    }
};
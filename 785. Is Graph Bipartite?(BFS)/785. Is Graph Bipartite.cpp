class Solution {
public:
    bool bfsCheck(int start, vector<int>& vis, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it: graph[node]) {
                if (vis[it] == -1) {
                    vis[it]  = !vis[node];
                    q.push(it);
                } else if (vis[it] == vis[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1);

        for (int i=0; i<V; i++) {
            if (vis[i] == -1) {
                if (!bfsCheck(i, vis, graph)) {
                    return false;
                }
            }
        }

        return true;
        
    }
};

---------------------------------------------
//DFS Approach

class Solution {
public:
    bool dfsCheck(int start, vector<int>& vis, vector<vector<int>>& graph) {

        for (auto it : graph[start]) {
            if (vis[it] == -1) {
                vis[it] = !vis[start];
                if (!dfsCheck(it, vis, graph)) {
                    return false;
                }
            } else if (vis[it] == vis[start]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1);

        for (int i=0; i<V; i++)  {
            if (vis[i] == -1) {
                vis[i] = 0;
                if (!dfsCheck(i, vis, graph)) {
                    return false;
                }
            }
        }

        return true;
    }
};
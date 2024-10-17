class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V, 1e8);
        dist[src] = 0;
        
        //Performing relaxation step on n-1 times
        for (int i=0; i<V-1; i++) {
            for (auto it: edges) {
                int u = it[0];
                int v = it[1];
                int weight = it[2];
                
                if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        
        //nth relaxation to check if negative is present or not
        for(auto it: edges) {
            int u = it[0];
            int v= it[1];
            int weight = it[2];
            
            if (dist[u] != 1e8 && dist[u]+weight < dist[v]) {
                return {-1};
                
            }
        }
        
        return dist;
    }
};
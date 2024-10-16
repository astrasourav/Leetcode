class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        typedef pair<int, int>P;
        priority_queue<P, vector<P>, greater<P>>pq;
        
        vector<int> vis(V, 0);
        // {weight, node}s
        pq.push({0, 0});
        int sum = 0;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            if (!vis[it.second]) {
                vis[it.second] = 1;
                sum += it.first;
                for (auto ik: adj[it.second]) {
                    int adjNode = ik[0];
                    int weight = ik[1];
                    
                    if (!vis[adjNode]) {
                        pq.push({weight, adjNode});
                    }
                }
            }
            
            
        }
        
        return sum;
        
    }
};
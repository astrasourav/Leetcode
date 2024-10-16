class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        typedef pair<int, int>P;
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<int>dist(V, INT_MAX);
        pq.push({0, S});
        dist[S] = 0;
        
        while (!pq.empty()) {
            auto node = pq.top();
            int dis = node.first;
            int value = node.second;
            pq.pop();
            
            for (auto it: adj[value]) {
                int adjNode = it[0];
                int adjWeight = it[1];
                
                if (dis + adjWeight < dist[adjNode]) {
                    dist[adjNode] = dis+adjWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        
        return dist;
    }
};
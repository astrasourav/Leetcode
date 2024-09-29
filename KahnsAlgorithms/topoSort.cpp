//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V] = {0};
	    queue<int>q;
	    vector<int> ans;
	    
	    for (int i=0; i<V; i++) {
	        for (auto it: adj[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    for (int i=0; i<V; i++) {
	        if (indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while (!q.empty()) {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for (auto it : adj[node]) {
	            indegree[it]--;
	            if (indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    
	    return ans;
	}
};

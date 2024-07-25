class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        
        int maxi = arr[n-1];
        vector<int> ans;
        
        for (int i=n-1; i>=0; i--) {
            if (arr[i] >= maxi) {
                maxi = arr[i];
                ans.push_back(arr[i]);
            }
            
            // maxi = max(arr[i], maxi);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

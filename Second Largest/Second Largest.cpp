class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        if (arr.size() < 2) return -1;
        int large = INT_MIN;
        int slarge = INT_MIN;
        
        int n = arr.size();
        
        for (int i=0; i<n; i++) {
            if (arr[i] > large) {
                slarge = large;
                large = arr[i];
            } else if (arr[i] != large && arr[i] > slarge) {
                slarge = arr[i];
            }
        }
        
        return slarge;
    }
};

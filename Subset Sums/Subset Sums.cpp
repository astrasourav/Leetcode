class Solution {
  public:
    void func(int ind, int sum, int n, vector<int>& arr, vector<int>& ans) {
        if (ind == n) {
            ans.push_back(sum);
            return;
        }
        
        //to pick element
        func(ind + 1, sum + arr[ind], n, arr, ans);
        
        //to no pick element
        func(ind + 1, sum, n, arr, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        func(0, 0, n, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

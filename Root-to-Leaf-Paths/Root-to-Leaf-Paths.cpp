class Solution {
  public:
    void solve(Node* root, vector<int>& tmp, vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }    
        
        tmp.push_back(root->data);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(tmp);
        }else {
            solve(root->left, tmp, ans);
            solve(root->right, tmp, ans);
            
        }
        tmp.pop_back();
        
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        vector<int> tmp;
        solve(root, tmp, ans);
        
        // ans.push_back(tmp);
        return ans;
    }
};

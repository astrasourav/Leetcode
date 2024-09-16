class Solution
{
    public:
    
    void helper(Node *root, int& k, int& ans) {
        
        if (root==NULL || k <= 0) {
            return;
        }
        
        helper(root->right, k, ans);
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        helper(root->left, k, ans);
        
    }
    
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int ans = -1;
        helper(root, k, ans);
        
        return ans;
        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int sum) {
        if (node == NULL) {
            return 0;
        }

        sum = sum*10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            return sum;
        }
        int left  = dfs(node->left, sum);
        int right = dfs(node->right, sum);

        return left+right;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

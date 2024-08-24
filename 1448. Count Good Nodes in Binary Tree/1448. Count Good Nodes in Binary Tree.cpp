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
    int countGoodNodes(TreeNode* node, int maxSoFar) {
        if (node == nullptr) return 0; // Base case: If node is null, return 0
        
        int good = 0;
        // If the current node's value is greater than or equal to maxSoFar, it's a good node
        if (node->val >= maxSoFar) {
            good = 1; // Count this node as a good node
        }
        
        // Update the maxSoFar to be the maximum of the current node's value and the maxSoFar
        maxSoFar = max(maxSoFar, node->val);
        
        // Count the good nodes in the left and right subtrees
        good += countGoodNodes(node->left, maxSoFar);
        good += countGoodNodes(node->right, maxSoFar);
        
        return good; // Return the total number of good nodes in this subtree
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0; // Edge case: If the tree is empty
        
        return countGoodNodes(root, root->val);
    }
};

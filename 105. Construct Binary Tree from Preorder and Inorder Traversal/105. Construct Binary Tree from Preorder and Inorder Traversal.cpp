class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;  // Base case
        }

        // The first element of preorder is the root of the current subtree
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root in the inorder traversal
        int rootIndex = inStart;
        while (inorder[rootIndex] != rootVal && rootIndex <= inEnd) {
            rootIndex++;
        }

        // Calculate the number of nodes in the left subtree
        int leftTreeSize = rootIndex - inStart;

        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd);

        return root;
    }
};


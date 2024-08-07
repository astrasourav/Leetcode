class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if (root == nullptr) {
            return nullptr;
        }

        if (curr == depth - 1) {
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = tempLeft;
            root->right->right = tempRight;

            return root;
        }

        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int curr = 1;
        return add(root, val, depth, curr);
    }
};


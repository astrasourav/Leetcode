class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();

            if (leftNode == NULL && rightNode == NULL) {
                continue;
            }
            if (leftNode == NULL || rightNode == NULL) {
                return false;
            }
            if (leftNode->val != rightNode->val) {
                return false;
            }

            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        return true;
    }
};


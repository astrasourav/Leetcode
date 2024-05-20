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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        if (root == NULL) return ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* tmp = it.first;
            int x = it.second.first;
            int y = it.second.second;

            nodes[x][y].insert(tmp->val);

            if (tmp->left != NULL) {
                q.push({tmp->left, {x - 1, y + 1}});
            }

            if (tmp->right != NULL) {
                q.push({tmp->right, {x + 1, y + 1}});
            }
        }

        for (auto it: nodes) {
            vector<int> col;
            for (auto q : it.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

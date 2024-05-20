class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if (root == NULL) return {};
        
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* tmp = it.first;
            int line = it.second;
            
            mp[line] = tmp->data;
            
            if (tmp->left != NULL) q.push({tmp->left, line - 1});
            if (tmp->right != NULL) q.push({tmp->right, line + 1});
        }
        
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

class Solution {
public:
    void LeftTravel(Node* root, vector<int> &ans) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) return;
        
        ans.push_back(root->data);
        if (root ->left != NULL) {
            LeftTravel(root->left, ans);
        } else {
            LeftTravel(root->right, ans);
        }
    }
    
    void LeafTravel(Node* root, vector<int> &ans) {
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        LeafTravel(root->left, ans);
        LeafTravel(root->right, ans);
    }
    
    void RightTravel(Node* root, vector<int>&ans) {
    
        if((root == NULL ) || ( root->left == NULL && root->right == NULL ))
            return;
        if(root->right)
            RightTravel(root->right, ans);
        else
            RightTravel(root->left, ans);
        
        ans.push_back(root->data);
        
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        if (root == NULL) return {};
        
        vector<int> ans;
        ans.push_back(root->data);
        
        LeftTravel(root->left, ans);
        
        LeafTravel(root->left, ans);
        LeafTravel(root->right, ans);
        
        RightTravel(root->right, ans);
        
        return ans;
    }
};



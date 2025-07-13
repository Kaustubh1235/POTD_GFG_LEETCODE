class Solution {
    TreeNode* ans = NULL;
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return false;
        
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        bool mid = (root == p || root == q);
        
        // If any two of the three flags left, right, mid become true
        if (mid + left + right >= 2) {
            ans = root;
        }
        
        return mid || left || right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

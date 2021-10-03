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
    const bool USEROOT = true;
    const bool NOROOT = false;
    map<pair<TreeNode*, bool>, int> dp;
    int rob(TreeNode* root) {
        dp.clear();
        return _rob(root, USEROOT);
    }
    
    int _rob(TreeNode* root, bool useRoot) {
        if (root == nullptr) return 0;
        
        // no take root
        int no_root = _rob(root->left, USEROOT) + _rob(root->right, USEROOT); 
        
        // take root
        int have_root = 0;
        if (useRoot) {
            have_root = root->val + dp[{root->left, NOROOT}] + dp[{root->right, NOROOT}];    
        }
        dp[{root, USEROOT}] = have_root;
        dp[{root, NOROOT}] = no_root;
        
        return max(no_root, have_root);
    }
};

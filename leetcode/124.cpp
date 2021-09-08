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
    int ans = -10000000;
    int maxPathSum(TreeNode* root) {
        recursiveHelper(root); 
        return ans;
    }
    
    int recursiveHelper(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = max(recursiveHelper(root->left), 0);
        int r = max(recursiveHelper(root->right), 0);
        ans = max(ans, root->val+l+r);
        return root->val + max(l, r);
    }
};

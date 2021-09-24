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
    vector<int> ans;
    int kthSmallest(TreeNode* root, int k) {
        traversal(root); 
        return ans[k-1];
    }
    void traversal(TreeNode* root) {
        if (root == nullptr) return;
        
        traversal(root->left);
        ans.push_back(root->val);
        traversal(root->right);
    }
};

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
// brute force recursive method
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left+right, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int height(TreeNode* root) {
        if (root == nullptr)  return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
// dfs method
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root); 
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int diameter = left + right;
        ans = max(ans, diameter);
        return 1 + max(left, right);
    }
};

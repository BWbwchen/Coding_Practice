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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root, nullptr, val, depth);
    }
    TreeNode* solve(TreeNode* root, TreeNode* parent, int val, int depth) {
        if (root == nullptr && depth > 1) {
            return nullptr;
        } else if (depth == 1) {
            // Create new node
            TreeNode* nn = new TreeNode(val);
            if (!parent) {
                nn->left = root;
            } else if (parent->left == root) {
                parent->left = nn;
                nn->left = root;
            } else {
                parent->right = nn;
                nn->right = root;
            }
            return nn;
        } else {
            root->left = solve(root->left, root, val, depth-1);
            root->right = solve(root->right, root, val, depth-1);
            return root; 
        }
    }
};

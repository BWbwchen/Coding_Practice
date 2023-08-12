/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // find the correct location of the node.
        TreeNode *target = new TreeNode(val);
        TreeNode *head = root;
        // insert it
        while (head) {
            if (val < head->val) {
                if (head->left == nullptr) {
                    head->left = target;
                    break;
                } else {
                    head = head->left;
                }
            } else if (head->val < val) {
                if (head->right == nullptr) {
                    head->right = target;
                    break;
                } else
                    head = head->right;
            } else {
                // nonreachable.
            }
        }
        if (head == nullptr)
            root = target;
        return root;
    }
};

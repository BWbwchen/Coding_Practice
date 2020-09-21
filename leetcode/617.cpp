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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        int val = 0;
        if (!t1 && t2) val = t2->val;
        else if (t1 && !t2) val = t1->val;
        else val = t1->val+t2->val;
        TreeNode* temp = new TreeNode(val);
        
        if (!t1 && t2) {
            temp->left = mergeTrees(nullptr, t2->left);
            temp->right = mergeTrees(nullptr, t2->right);
        } 
        else if (t1 && !t2) {
            temp->left = mergeTrees(t1->left, nullptr);
            temp->right = mergeTrees(t1->right, nullptr);
        } 
        else {
            temp->left = mergeTrees(t1->left, t2->left);
            temp->right = mergeTrees(t1->right, t2->right);
        }
        return temp;
    }
};

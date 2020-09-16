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
    void flatten(TreeNode* root) {
        if (!root) return ;
        // preorder 
        stack<TreeNode* > st;
        if (root->right) st.push(root->right);
        if (root->left) st.push(root->left);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            root->left = nullptr;
            root->right = new TreeNode(top->val);
            root = root->right;
            if (top->right) st.push(top->right);
            if (top->left) st.push(top->left);
        }
    }
};

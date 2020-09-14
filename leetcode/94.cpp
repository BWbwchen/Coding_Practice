class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > ans;
        helper(ans, root);
        return ans;
    }
    
    void helper(vector<int >& ans, TreeNode* root) {
        if (root == nullptr) return ;
        helper(ans, root->left);
        ans.push_back(root->val);
        helper(ans, root->right);
    }
};

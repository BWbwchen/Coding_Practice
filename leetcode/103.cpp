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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        bool direction = false;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        
        
        while(!q.empty()) {
            auto top_p = q.front();
            q.pop();
            TreeNode* top = top_p.first;
            int level = top_p.second;
            
            // push into answer vector
            if (level > ans.size()) {
                vector<int> n = {top->val};
                ans.push_back(n);
            } else {
                ans[level-1].push_back(top->val);
            }
            
            
            if (top->right) q.push({top->right, level+1}); 
            if (top->left) q.push({top->left, level+1}); 
        }
        
        
        for (int i = 0; i < ans.size(); ++i) {
            if (i%2 == 0) reverse(ans[i].begin(), ans[i].end());
        }
        
        return ans;
    }
};

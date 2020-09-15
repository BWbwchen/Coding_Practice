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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        vector<vector<int >> res;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top.first == nullptr) continue;
            // push into res vector
            if (res.size() <= top.second) {
                res.push_back({top.first->val});
            } else {
                res[top.second].push_back(top.first->val);
            }
            // push the child
            q.push({top.first->left, top.second+1});
            q.push({top.first->right, top.second+1});
        }
        return res;
    }
};

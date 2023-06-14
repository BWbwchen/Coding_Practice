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
    int getMinimumDifference(TreeNode *root) {
        // bfs
        vector<int> d;
        queue<TreeNode *> q;
        q.emplace(root);

        while (!q.empty()) {
            auto top = q.front();
            if (top == nullptr) {
                continue;
            }

            q.pop();

            d.emplace_back(top->val);
            if (top->left)
                q.emplace(top->left);
            if (top->right)
                q.emplace(top->right);
        }

        // find minimum difference
        int n = d.size();
        int ret = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ret = min(ret, abs(d[i] - d[j]));
            }
        }
        return ret;
    }
};

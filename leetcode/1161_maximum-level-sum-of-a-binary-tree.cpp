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
#include <bits/stdc++.h>

#include <limits>
class Solution {
public:
    // BFS first, and sum up the value of same level
    // find the maximum sum level next.
    int maxLevelSum(TreeNode *root) {
        vector<int> sum;
        // {node, level}
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (top.first == nullptr) {
                continue;
            }

            TreeNode *node = top.first;
            int level = top.second;

            if (sum.size() < level) {
                sum.emplace_back(node->val);
            } else {
                sum[level - 1] += node->val;
            }

            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        int max_sum = std::numeric_limits<int>::min();
        int level = -1;
        for (int i = 0; i < sum.size(); ++i) {
            if (max_sum < sum[i]) {
                max_sum = sum[i];
                level = i + 1;
            }
        }
        return level;
    }
};

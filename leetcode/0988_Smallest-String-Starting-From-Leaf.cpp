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
    vector<string> candidate;
    string now;
    string smallestFromLeaf(TreeNode* root) {
        candidate.clear();
        now = "";
        traverse(root);
        return *std::min_element(candidate.begin(),candidate.end());
    }
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            candidate.push_back(now);
            return;
        } else {
            char c = root->val + 'a';
            string tmp = "";
            tmp += c;
            now.insert(0, tmp);
            if (root->left)
                traverse(root->left);
            if (root->right)
                traverse(root->right);

            if (!root->left && !root->right)
                candidate.push_back(now);
            now.erase(0, 1);
        }
    }
};

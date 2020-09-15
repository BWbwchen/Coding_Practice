#define ll long long int 
#define MAX 9223372036854775807
#define MIN -9223372036854775807
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, MIN, MAX);
    }
    
    bool helper(TreeNode* root, ll min, ll max) {
        if (root == nullptr) return true;
        if (min >= (ll)(root->val) || (ll)(root->val) >= max) return false;
        return helper(root->left, min, root->val) && 
               helper(root->right, root->val, max);
    }
};

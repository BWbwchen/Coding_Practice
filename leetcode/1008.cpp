/**
 * Definition for a binary tree node.
*/
 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
class Solution {
public:
    std::vector<int> pre;
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        pre = preorder;
        return buildTree(0, preorder.size()-1);
    }
    
    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;
        TreeNode* root = new TreeNode(pre[start]);
        int mid = findNextLarge(start+1, end, pre[start]);
        root->left = buildTree(start+1, mid-1);
        root->right = buildTree(mid, end);
        return root;
    }
    
    int findNextLarge(int start, int end, int target) {
        for (int i = start; i <= end; ++i) {
            if (target < pre[i]) {
                return i; 
            } 
        } 
        return end+1;
    }
};

class Solution2 {
public:
    std::vector<int> pre;
    int id;
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        pre = preorder;
        id = 0;
        return buildTree(100000);
    }
    
    TreeNode* buildTree(int bound) {
        if (id >= pre.size() || pre[id] > bound) return nullptr;
        TreeNode* root = new TreeNode(pre[id++]);
        root->left = buildTree(root->val);
        root->right = buildTree(bound);
        return root;
    }
};

int main(){
  Solution solution;
  Solution2 solution2;
  return 0;
}
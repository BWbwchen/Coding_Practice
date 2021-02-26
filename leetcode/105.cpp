// beat 68.53%
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        auto rootNode = preorder[0];
        int rootIndexInorder = find(inorder.begin(), inorder.end(), rootNode) - inorder.begin();
        int leftLength = rootIndexInorder;
        int rightLength = inorder.size() - 1 - leftLength;
        // find the root index in inorder
        // recursive
        vector<int> preorderLeft = vector<int>(preorder.begin() + 1, preorder.begin() + 1+leftLength);
        vector<int> preorderRight = vector<int>(preorder.begin() + 1 + leftLength, preorder.end());
        vector<int> inorderLeft = vector<int>(inorder.begin(), inorder.begin() + leftLength);
        vector<int> inorderRight = vector<int>(inorder.begin() + leftLength + 1, inorder.end());
        
        TreeNode *rightNode = buildTree(preorderRight, inorderRight);
        TreeNode *leftNode = buildTree(preorderLeft, inorderLeft);
        TreeNode *tempRoot = new TreeNode(rootNode, leftNode, rightNode);
        return tempRoot; 
    }
};

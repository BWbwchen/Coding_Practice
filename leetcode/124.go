/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans int = -1000000;
func maxPathSum(root *TreeNode) int {
    ans = -100000000;
    recursiveHelper(root);
    return ans;
}

func recursiveHelper(root *TreeNode) int {
    if root == nil {
        return 0;
    }
    
    l := max(recursiveHelper(root.Left), 0);
    r := max(recursiveHelper(root.Right), 0);
    ans = max(ans, root.Val+l+r);
    return root.Val + max(l, r);
}

func max(a, b int) int {
    if a > b {
        return a;
    } 
    return b;
}

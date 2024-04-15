// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::solve(root, 0)
    }
    fn solve(root: Option<Rc<RefCell<TreeNode>>>, base: i32) -> i32 {
        let mut ret = 0;

        if let Some(root) = root {
            // check whether it is leaf node
            let mut node = root.borrow_mut();

            if node.left.is_none() && node.right.is_none() {
                ret = 10 * base + node.val;
            } else {
                let left = Self::solve(node.left.take(), 10 * base + node.val);
                let right = Self::solve(node.right.take(), 10 * base + node.val);
                ret = left + right;
            }
        }

        ret
    }
}

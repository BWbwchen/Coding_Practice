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
#[derive(Copy, Clone)]
enum DIR {
    LEFT,
    RIGHT,
}
impl Solution {
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::solve(root, DIR::RIGHT)
    }
    fn solve(root: Option<Rc<RefCell<TreeNode>>>, dir: DIR) -> i32 {
        let mut ret = 0;
        if let Some(root) = root {
            let mut node = root.borrow_mut();
            if node.left.is_none() && node.right.is_none() {
                // leaf node
                ret = match dir {
                    DIR::LEFT => node.val,
                    _ => 0,
                };
            } else {
                let left = Self::solve(node.left.take(), DIR::LEFT);
                let right = Self::solve(node.right.take(), DIR::RIGHT);


                ret = left + right;
            }
        }
        ret
    }

}

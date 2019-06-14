# DFS
---

## Binary Tree

### Method_1. use recursion

For pre-order (root->left->right):

    print(root)
    print(left_tree)
    print(right_tree)

For in-order (left->root->right):

    print(left_tree)
    print(root)
    print(right_tree)

For post-order (left->right->root):

    print(left_tree)
    print(right_tree)
    print(root)

### Method_2. use stack

For pre-order (root->left->right):

    stack.push(root)
    while(!stack.empty()) {
        1. pop out the top node
        2. push the top node's right side node
        3. push the top node's left side node        
    }

For in-order (left->root->right):

    stack.push(root)
    while(stack.top() has child node) {
        1. pop out the top node
        2. push the top node's right side node
        3. push the top node itself again
        4. push the top node's left side node        
    }

For post-order (left->right->root):

    stack.push(root)
    while(stack.top() has child node) {
        1. pop out the top node
        2. push the top node's left side node        
        3. push the top node's right side node
        4. push the top node itself again
    }
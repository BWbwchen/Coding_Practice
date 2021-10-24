/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let head = new ListNode(-1, null);
    let th = head;
    let carry = 0;
    
    
    while (l1 && l2) {
        th.next = new ListNode((l1.val + l2.val + carry)%10, null) ;
        carry = (l1.val + l2.val + carry) >= 10 ? 1 : 0;
        th = th.next;
        l1 = l1.next;
        l2 = l2.next;
    }
    
    while(l1) {
        th.next = new ListNode((l1.val + carry)%10, null) ;
        carry = (l1.val + carry) >= 10 ? 1 : 0;
        th = th.next;
        l1 = l1.next;
    }
    
    while(l2) {
        th.next = new ListNode((l2.val + carry)%10, null) ;
        carry = (l2.val + carry) >= 10 ? 1 : 0;
        th = th.next;
        l2 = l2.next;
    }
    
    if (carry != 0) {
        th.next = new ListNode(carry, null) ;
        th = th.next;
    }

    return head.next
};

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    if (head == nil || head.Next == nil) {
        return head
    }   
    
    slow := head
    fast := head.Next;
    
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    
    half := slow.Next
    slow.Next = nil
    
    return Merge(sortList(head), sortList(half))
}

func Merge(l1 *ListNode, l2 *ListNode) *ListNode {
    var res *ListNode = nil
    var temp_head *ListNode = nil
    
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            if res == nil {
                res = l1 
                temp_head = l1 
            } else {
                temp_head.Next = l1
                temp_head = temp_head.Next
            }
            l1 = l1.Next 
        } else {
            if res == nil {
                res = l2 
                temp_head = l2 
            } else {
                temp_head.Next = l2
                temp_head = temp_head.Next
            }
            l2 = l2.Next 
        }
    }
    
    for l1 != nil {
        if res == nil {
            res = l1 
            temp_head = l1 
        } else {
            temp_head.Next = l1
            temp_head = temp_head.Next
        }
        l1 = l1.Next 
    }
    
    for l2 != nil {
        if res == nil {
            res = l2 
            temp_head = l2 
        } else {
            temp_head.Next = l2
            temp_head = temp_head.Next
        }
        l2 = l2.Next 
    }
    
    return res
}

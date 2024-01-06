/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode *head;
    struct ListNode **indirect = &head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            *indirect = list1;
            list1 = list1->next;
        } else {
            *indirect = list2;
            list2 = list2->next;
        }
        indirect = &(*indirect)->next;
    }

    *indirect = (struct ListNode *) ((uintptr_t) list1 | (uintptr_t) list2);

    return head;
}

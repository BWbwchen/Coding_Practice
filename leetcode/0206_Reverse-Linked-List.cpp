/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        else if (head->next == nullptr)
            return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return res;
    }
};

// iterative method
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *now = head;
        ListNode *next = head;

        while (now) {
            next = now->next;
            now->next = prev;
            prev = now;
            now = next;
        }

        return prev;
    }
};

// Naive method, double for loop O(n^2)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (ListNode *A = headA; A; A = A->next) {
            for (ListNode *B = headB; B; B = B->next) {
                if (A == B)
                    return A;
            }
        }
        return nullptr;
    }
};

// O(n)
class Solution {
public:
    int cal_len(ListNode *root) {
        if (root == nullptr)
            return 0;
        else
            return 1 + cal_len(root->next);
    }
    ListNode *shift(ListNode *root, int delta) {
        while (delta-- && root) {
            root = root->next;
        }
        return root;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = cal_len(headA);
        int lenB = cal_len(headB);
        ListNode *newA = headA;
        ListNode *newB = headB;

        // [BW] Make them the same length first
        if (lenA > lenB) {
            newA = shift(newA, lenA - lenB);
        } else if (lenA < lenB) {
            newB = shift(newB, lenB - lenA);
        }

        while (newA && newB) {
            if (newA == newB)
                return newA;
            newA = newA->next;
            newB = newB->next;
        }

        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *curA = headA;
        ListNode *curB = headB;

        while (curA != curB) {
            // we can repeat curA or curB multiple time
            curA = (curA) ? curA->next : headB;
            curB = (curB) ? curB->next : headA;
        }
        return curA;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        int b = 0;
        ListNode *la = headA;
        ListNode *lb = headB;
        while (la) {
            a++;
            la = la->next;
        }
        while (lb) {
            b++;
            lb = lb->next;
        }

        int m = min(a, b);

        la = headA;
        while (a > m && la) {
            a--;
            la = la->next;
        }

        lb = headB;
        while (b > m && lb) {
            b--;
            lb = lb->next;
        }

        while (la && lb) {
            if (la == lb) {
                return la;
            }
            la = la->next;
            lb = lb->next;
        }

        return nullptr;
    }
};

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
// O(n) with memory O(n)
class Solution {
public:
    vector<int> t;
    bool isPalindrome(ListNode* head) {
        traversal(head); 
        return palindrome();
    }
    
    void traversal(ListNode* head) {
        ListNode* h = head;
        while(h) {
            t.push_back(h->val);
            h = h->next;
        }
    }
    
    bool palindrome() {
        for (int i = 0; i < t.size()/2; ++i) {
            if (t[i] != t[t.size()-i-1]) return false; 
        }
        return true;
    }
};

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
// O(n) with memory O(1)
class Solution {
public:
    ListNode* h1;
    ListNode* h2;
    bool isPalindrome(ListNode* head) {
        myReverseHalf(head);
        return palindrome(head);
    }
    
    void myReverseHalf(ListNode* head) {
        if (head == nullptr) return;
        ListNode* slow = head; 
        ListNode* fast = head; 
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        h2 = slow;
        
        
        // reverse
        ListNode* now = head;
        ListNode* pre = nullptr;
        ListNode* nex = head->next;
        while(now && now != h2) {
            now->next = pre;
            pre = now;
            now = nex;
            if (nex) nex = nex->next;
        }
        
        h1 = pre;
        if (fast) h2 = h2->next;
    }
    
    bool palindrome(ListNode* head) {
        while(h1 && h2 ){
            if (h1->val != h2 ->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};

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
// faster than 36.08% solution
// use priority_queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // heap sort
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        //priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        ListNode* head = nullptr;
        ListNode* temp = head;
        // 1. Push the head of the list into heap
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                heap.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        
        while (!heap.empty()) {
            // pop root
            auto top = heap.top();
            heap.pop();
            if (head == nullptr) {
                head = new ListNode(top.first);
                temp = head;
            } else {
                temp->next = new ListNode(top.first);
                temp = temp->next;
            }
            // push that list's head 
            if (lists[top.second] != nullptr) {
                heap.push({lists[top.second]->val, top.second});
                lists[top.second] = lists[top.second]->next;
            }
        }
        
        return head;        
    }
};

// use the same concept as we do merge two sorted lists
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(0, lists.size()-1, lists);      
    }
    ListNode* merge(int start, int end, vector<ListNode*> lists) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        
        int mid = start + (end - start)/2;
        ListNode* left = merge(start, mid, lists);
        ListNode* right = merge(mid+1, end, lists);
        return merger(left, right);
    }
    ListNode* merger(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        if (left->val < right->val) {
            left->next = merger(left->next, right);
            return left;
        } else {
            right->next = merger(left, right->next);
            return right;
        }
    }
};


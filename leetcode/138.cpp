/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        map<Node* , Node*> mp;
        Node* temp = head;
        Node* res = nullptr;
        // copy next
        while (temp) {
            Node* n = new Node(temp->val);
            mp[temp] = n;
            if (!res) {
                res = n;
            } else {
                res->next = n;
                res = res->next;
            }
            temp = temp->next;
        }
        
        // copy random
        temp = head;
        res = mp[temp];
        while (temp) {
            res->random = mp[temp->random];
            res = res->next;
            temp = temp->next;
        }
        
        return mp[head];
    }
    
};

class MinStack {
public:
    /** initialize your data structure here. */
    class Node {
    public:
        int val;
        int min;
        Node* next;
        
        Node(int _val, int _min, Node* _next) {
            val = _val;
            min = _min;
            next = _next;
        }
    };
    
    Node *head;
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, min(val, head->min), head);
        }
    }
    
    void pop() {
        head = head->next; 
    }
    
    int top() {
        return head->val; 
    }
    
    int getMin() {
        return head->min; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    // val, min
    vector<pair<int, int>> v;
    MinStack() {
    }
    
    void push(int val) {
        if (v.empty()) {
            v.push_back(make_pair(val, val)); 
        } else {
            v.push_back(make_pair(val, min(val, v.back().second)));
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second; 
    }
};

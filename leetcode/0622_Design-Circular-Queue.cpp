class MyCircularQueue {
public:
    int head;
    int tail;
    int capacity;
    vector<int> q;

public:
    int legalize(int x) {
        x %= capacity;
        return x;
    }
    MyCircularQueue(int k) {
        head = -1;
        tail = -1;
        q.resize(k, -1);
        capacity = k;
    }

    bool enQueue(int value) {
        // move tail, tail++
        if (isFull())
            return false;
        if (isEmpty()) {
            head = tail = 0;
            q[tail] = value;
        } else {
            tail++;
            tail = legalize(tail);
            q[tail] = value;
        }
        return true;
    }

    bool deQueue() {
        // move head, --head
        if (isEmpty())
            return false;

        if (head == tail) {
            head = tail = -1;
            return true;
        }
        head++;
        head = legalize(head);
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return q[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return q[tail];
    }

    bool isEmpty() { return head == -1 && tail == -1; }

    bool isFull() { return legalize(tail + 1) == head; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

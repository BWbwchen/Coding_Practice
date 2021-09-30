class MedianFinder {
public:
    priority_queue<int,std::vector<int>, greater<int>> increase;
    priority_queue<int> decrease;
    bool even = true;
    MedianFinder() {
        even = true; 
    }
    
    void addNum(int num) {
        if (even) {
            increase.push(num);
            decrease.push(increase.top()); 
            increase.pop();
        } else {
            decrease.push(num); 
            increase.push(decrease.top());
            decrease.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if (even) {
            return ((double)(increase.top() + decrease.top()))/2;
        } else {
            return decrease.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

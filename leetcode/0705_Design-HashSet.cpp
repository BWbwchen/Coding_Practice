class MyHashSet {
private:
    unordered_set<int> us;

public:
    MyHashSet() { us.clear(); }

    void add(int key) { us.emplace(key); }

    void remove(int key) { us.erase(key); }

    bool contains(int key) { return us.count(key); }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

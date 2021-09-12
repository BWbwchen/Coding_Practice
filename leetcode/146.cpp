class LRUCache {
  private:
    list<pair<int, int>> recently; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;
    
    void update(list<pair<int, int>>::iterator it) {
        recently.splice(recently.begin(), recently, it); 
    }
  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            update(cache[key]);
            return cache[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            update(cache[key]);
        } else {
            if (cache.size() >= this->capacity) {
                cache.erase(recently.back().first);
                recently.pop_back();
                
                recently.push_front(make_pair(key, value));
                cache[key] = recently.begin();
            } else {
                recently.push_front(make_pair(key, value));
                cache[key] = recently.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


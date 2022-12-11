class Allocator {
public:
    vector<int> mem;
    Allocator(int n) {
        mem.resize(n, -1);
    }
    
    int find_consecutive(int start, int size) {
        if (start + size - 1 >= mem.size())
            return -1;
        bool con = true;
        int i;
        for (i = start; i < start + size && i < mem.size(); ++i) {
            if (mem[i] != -1)  {
                con = false;
                break;
            }
        } 
        if (con)
            return start;
        else 
            return i+1;
    }
    
    int find_free_id(int size) {
        int free_id;
        int i = 0;
        while(i < mem.size()) {
            if (mem[i] == -1) {
                free_id = find_consecutive(i, size);
                if (free_id == i)
                    return free_id;
                else if (free_id == -1)
                    return -1;
                else  {
                   i = free_id; 
                }
            } else {
                i++;
            }
        }
        return -1;
    }
    
    int allocate(int size, int mID) {
        int free_id = find_free_id(size);
        if (free_id == -1) {
            return -1;
        } 
        
        for (int i = free_id; i < free_id + size; ++i) {
            mem[i] = mID;
        }
        return free_id;
    }
    
    int free(int mID) {
        int ans = 0;
         for (int i = 0; i < mem.size(); ++i) {
             if (mem[i] == mID) {
                 ans ++;
                 mem[i] = -1;
             }
         }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

class SnapshotArray {
public:
    int st_length;
    int time;
    // index -> snap_id, val
    // use map for binary search of snap_id.
    vector<map<int, int>> st;
    SnapshotArray(int length) {
        st_length = length;
        time = 0;
        st.resize(length);
        for (int i = 0; i < length; ++i) {
            st[i][time] = 0;
        }
    }

    void set(int index, int val) { st[index][time] = val; }

    int snap() {
        time++;
        return time - 1;
    }

    int get(int index, int snap_id) {
        if (st[index].find(snap_id) == st[index].end()) {
            auto it = --st[index].lower_bound(snap_id);
            return it->second;
        }
        return st[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

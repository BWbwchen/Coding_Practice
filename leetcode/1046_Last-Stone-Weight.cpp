class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        int size = stones.size();
        while (size > 1) {
            sort(stones.begin(), stones.end(), greater<int>());
            if (stones[0] == stones[1]) {
                stones.erase(stones.begin(), stones.begin() + 2);
                size -= 2;
            } else {
                stones[0] -= stones[1];
                stones.erase(stones.begin() + 1, stones.begin() + 2);
                size--;
            }
        }
        return size == 1 ? stones[0] : 0;
    }
};

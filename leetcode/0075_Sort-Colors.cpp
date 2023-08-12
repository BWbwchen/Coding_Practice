class Solution {
public:
    void sortColors(vector<int> &nums) {
        // one-pass algorithm using only constant extra space -> counting sort
        array<int, 3> counting = {0, 0, 0};

        for (auto &n : nums) {
            counting[n]++;
        }

        int id = 0;
        for (auto &n : nums) {
            while (counting[id] <= 0)
                id++;

            n = id;
            counting[id]--;
        }
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int start = 0;
        int run = 0;
        for (int i = 0; i < gas.size(); ++i) {
            int delta = gas[i] - cost[i];
            sum += delta;
            run += delta;
            if (run < 0) {
                start = i + 1;
                run = 0;
            }
        }
        return (sum >= 0) ? start : -1;
    }
};

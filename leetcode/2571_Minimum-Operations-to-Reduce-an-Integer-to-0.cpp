// dfs
class Solution {
public:
    int lowbit(int x) { return x & -x; }
    int minOperations(int n) {
        int lb = lowbit(n);
        if (n - lb == 0)
            return 1;

        return min(minOperations(n - lb), minOperations(n + lb)) + 1;
    }
};

// greedy
class Solution {
public:
    int lowbit(int x) { return x & -x; }
    int power_of_two(int x) { return !(x & (x - 1)); }
    int minOperations(int n) {
        int lb;
        int answer = 0;
        while (!power_of_two(n)) {
            lb = lowbit(n);
            // consecutive 1s
            if (n & (lb << 1)) {
                // add lb
                n += lb;
                answer++;
            } else {
                // minus lb
                n -= lb;
                answer++;
            }
        }
        return answer + 1;
    }
};

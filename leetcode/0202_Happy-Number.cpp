// brute force method
class Solution {
public:
    long long int result(long long int n) {
        long long int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_map<int, bool> record;
        long long int tmp;
        while (true) {
            tmp = result(n);
            if (record.count(tmp))
                return false;
            else
                record.emplace(tmp, true);
            n = tmp;
            if (n == 1)
                return true;
        }
        return false;
    }
};

// since we want to know whether it has cycle or not.
// We can use slow and fast pointer!
class Solution {
public:
    long long int result(long long int n) {
        long long int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        long long int slow = n, fast = n;
        do {
            slow = result(slow);
            fast = result(result(fast));
        } while (slow != fast);
        return slow == 1;
    }
};

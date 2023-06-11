class Solution {
    using ll = long long;

public:
    ll bs_sum(ll tmp_answer, ll index, ll n) {
        ll left = tmp_answer - 2;
        ll left_idx = index - 1;
        ll left_answer = (2 * left - left_idx) * (left_idx + 1) / 2;
        if (left <= left_idx) {
            left_answer = ((left + 1LL) * left) / 2;
        }

        if (left_idx < 0)
            left_answer = 0;

        ll right = tmp_answer - 2;
        ll right_idx = index + 1;
        ll right_answer =
            (2 * right - (n - 1 - right_idx)) * (n - 1 - right_idx + 1) / 2;
        if (right <= (n - 1 - right_idx)) {
            right_answer = ((right + 1LL) * right) / 2;
        }
        if (right_idx == n)
            right_answer = 0;

        cout << "left_answer: " << left_answer
             << ", right_answer: " << right_answer << endl;
        return left_answer + right_answer + tmp_answer - 1LL + n;
    }
    int maxValue(int n, int index, int maxSum) {
        ll left = 1;
        ll right = maxSum;
        ll answer = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            ll sum = bs_sum(mid, index, n);
            cout << left << ", " << mid << ", " << right << endl;
            if (sum < maxSum) {
                cout << sum << "less than " << maxSum << endl;
                answer = mid;
                left = mid + 1;
            } else if (sum > maxSum) {
                cout << sum << "greater than " << maxSum << endl;
                right = mid - 1;
            } else {
                answer = mid;
                break;
            }
        }
        return answer;
    }
};

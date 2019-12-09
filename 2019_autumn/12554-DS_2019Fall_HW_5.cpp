#define DEBUG
#define MAXN 2147483647
#include <bits/stdc++.h>

using namespace std;

class Problem {
   private:
    int length;
    int radix;
    vector<int> sequence;
    vector<int> m_temp;

    // sort by num/mul % radix
    void countingsort(int mul) {
        // counting
        vector<int> counting(radix, 0);
        for (int i = 0; i < length; ++i) {
            counting[(sequence[i] / mul) % radix]++;
        }

        // accumulate so assign sort array will more easier
        for (int i = 1; i < counting.size(); ++i)
            counting[i] += counting[i - 1];

        vector<int> temp_ans(length, 0);
        // NOTICE HERE
        for (int i = length - 1; i >= 0; --i) {
            temp_ans[counting[(sequence[i] / mul) % radix] - 1] = sequence[i];
            counting[(sequence[i] / mul) % radix]--;
        }

        sequence = temp_ans;
        cout << sequence.front() << " " << sequence.back() << endl;
    }
    int merge(int front, int mid, int end) {
        // need to consider only one
        vector<int> left(m_temp.begin() + front, m_temp.begin() + mid + 1),
            right(m_temp.begin() + mid + 1, m_temp.begin() + end + 1);
        left.insert(left.end(), MAXN);
        right.insert(right.end(), MAXN);

        int Lindex = 0, Rindex = 0;
        int to_return = 0;
        for (int i = front; i <= end; ++i) {
            if (left[Lindex] > right[Rindex]) {
                m_temp[i] = right[Rindex++];
                to_return += ((mid - front + 1) - Lindex);
            } else {
                m_temp[i] = left[Lindex++];
            }
        }
        return to_return;
    }
    int mergesort(int front, int end) {
        int ans = 0;
        if (front < end) {
            int mid = (front + end) / 2;
            ans += mergesort(front, mid);
            ans += mergesort(mid + 1, end);
            ans += merge(front, mid, end);
        }
        return ans;
    }

   public:
    Problem() {
        length = 0;
        radix = 0;
    }
    void input(int total) {
        cin >> radix;
        length = total;
        int temp;
        sequence.clear();
        for (int i = 0; i < length; ++i) {
            cin >> temp;
            sequence.push_back(temp);
        }
        m_temp = sequence;
    }
    void merge_sort() {
        cout << mergesort(0, length - 1) << endl;
    }
    void radix_sort() {
        // find the max
        int max = -MAXN;
        for (int i = 0; i < length; ++i) {
            if (sequence[i] > max) max = sequence[i];
        }

        int mul = 1;
        while (max) {
            countingsort(mul);
            mul *= radix;
            max /= radix;
        }
    }
};

int main() {
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    Problem t;
    int total;
    while (cin >> total) {
        t.input(total);
        t.merge_sort();
        t.radix_sort();
    }
    return 0;
}


#define DEBUG
#define MAXN 1e9
#include <bits/stdc++.h>

using namespace std;

class Problem {
    private :
        int length;
        int radix;
        vector<int> sequence;

        // sort by num/mul % radix
        void countingsort(int mul) {
            // counting
            vector<int > counting(radix, 0);
            for (int i = 0; i < length; ++i) {
                counting[(sequence[i]/mul)%radix]++;
            }

            // accumulate so assign sort array will more easier
            for (int i = 1; i < counting.size(); ++i) 
                counting[i] += counting[i-1];

            vector<int > temp_ans(length, 0);
            // NOTICE HERE
            for (int i = length - 1; i >= 0; --i) {
                temp_ans[counting[(sequence[i]/mul)%radix]-1] = sequence[i];
                counting[(sequence[i]/mul)%radix]--;
            }

            sequence = temp_ans;
            cout << sequence[0] << " " << sequence[length-1] << endl;
        }
    public:
        Problem () {
            cin >> length >> radix;
            int temp ;
            for (int i = 0; i < length; ++i) {
                cin >> temp; 
                sequence.push_back(temp);
            }
        }
        void inversion_pair_count () {
            int count = 0;
            for (int i = 0; i < length; ++i) {
                for (int j = 0; j < length; ++j) {
                    if (i < j && sequence[i] > sequence[j])
                        count++;
                }
            }
            cout << count << endl;
        }
        void radix_sort () {
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
    t.inversion_pair_count();
    t.radix_sort();
    


    return 0;
}


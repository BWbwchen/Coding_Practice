class Solution {
public:
    int kthFactor(int n, int k) {
        int middle = (int)sqrt((double)n);
        
        vector<int> li;
        
        for (int i = 1; i <= middle; ++i) {
            if (n % i == 0) {
                li.push_back(i);
                if (i * i != n) li.push_back(n / i);
            }
        }
        
        if (k > li.size()) return -1;
        
        sort(li.begin(), li.end());
        
        return li[k-1];
    }
};

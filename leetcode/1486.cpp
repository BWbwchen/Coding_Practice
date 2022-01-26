class Solution {
public:
    int xorOperation(int n, int start) {
        //return method1(n, start);
        return method2(n, start);
    }
    
    int method1(int n, int start) {
        vector<int> v(n, start);
        
        for (int i = 0; i < n; ++i) {
            v[i] += 2*i;
        }
        
        int ans = v[0];
        for (int i = 1; i < n; ++i) {
            ans ^= v[i];    
        }
         
        return ans;
    }
    int method2(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= start;
            start += 2;
        }
        return ans;
    }
};

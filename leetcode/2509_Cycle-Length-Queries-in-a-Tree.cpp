class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        // log2(x+1) + log2(x+1) - 1
        vector<int> ret;
        for(auto &q : queries) {
            auto &a = q[0];
            int aa = ceil(log2(a+1));
            auto &b = q[1];
            int bb = ceil(log2(b+1));
            
            int ret_aa = aa;
            int ret_bb = bb;
            
            int common = 0;
            while(true) {
                if (aa < bb) {
                    b/=2;
                    bb = ceil(log2(b+1));
                } else if (aa > bb) {
                    a /= 2;
                    aa = ceil(log2(a+1));
                } else if (aa == bb) {
                    if (a == b) {
                        break;
                    }
                    a /= 2;
                    b /= 2;
                }
            }
            common = ceil(log2(a+1));
            
            ret.emplace_back(ret_aa + ret_bb - 2*common + 1);
        }
        return ret;
    }
};

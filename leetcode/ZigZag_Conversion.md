# ZigZag Conversion

## by calculate the index
```c++=
class Solution {
public:
    string convert(string s, int numRows) {
        string answer;
        if (numRows == 1) return s;
        for (int i = 0; i < numRows; ++i) {
            int k = i;
            cout << k << " " << s.length() << endl;
            while (k < s.length()) {
                answer.push_back(s[k]);
                k += 2*(numRows - i -1);
                if (k >= s.length()) break;
                if ((i != 0) && (i != (numRows-1))) answer.push_back(s[k]);
                k += 2*i;
            }
        }
        return answer;
    }
};
```

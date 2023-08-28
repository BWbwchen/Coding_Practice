class Solution {
public:
    int compress(vector<char> &chars) {
        string ret = "";

        char c = chars[0];
        int count = 1;
        for (int i = 1; i < chars.size(); ++i) {
            if (c != chars[i]) {
                if (count == 1) {
                    ret += c;
                } else {
                    ret += c + to_string(count);
                }
                count = 1;
                c = chars[i];
            } else {
                count++;
            }
        }
        if (count == 1) {
            ret += c;
        } else {
            ret += c + to_string(count);
        }

        chars.clear();
        for (auto &c : ret) {
            chars.emplace_back(c);
        }
        return ret.size();
    }
};

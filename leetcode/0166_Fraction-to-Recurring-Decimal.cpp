class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string ans = "";

        bool negative = false;

        long long n = numerator, d = denominator;

        if (n < 0 && d > 0) {
            negative = true;
            n *= -1;
        } else if (n >= 0 && d < 0) {
            negative = true;
            d *= -1;
        } else if (n < 0 && d < 0) {
            n *= -1;
            d *= -1;
        }

        string s_num;
        if (n > d) {
            ans += to_string(n / d);
            n = n % d;
        } else {
            ans += "0";
        }

        if (negative) {
            ans = "-" + ans;
        }

        if (n == 0)
            return ans;

        ans += ".";

        unordered_map<int, int> record;

        while (true) {
            ans += to_string(n * 10 / d);
            if (n * 10 % d == 0) {
                break;
            } else {
                n = (n * 10) % d;
                if (record.count(n) > 0) {
                    int id = record[n];
                    ans.insert(id, "(");
                    ans += ")";
                    break;
                } else {
                    record[n] = ans.size();
                }
            }
        }

        return ans;
    }
};

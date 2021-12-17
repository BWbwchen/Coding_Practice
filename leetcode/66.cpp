class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (auto &n : digits) {
            int temp = n + carry;
            carry = temp / 10;
            n = temp % 10;
        }
        
        if (carry != 0) {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

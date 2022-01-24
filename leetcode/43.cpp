class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int len = num1.length() + num2.length();
        vector<int> product(len, 0);
        
        for (int i = num1.length() - 1; i >= 0; --i) {
            int a = num1[i] - '0';
            for (int j = num2.length() - 1; j >= 0; --j) {
                int b = num2[j] - '0';
                int answer_index = i + j + 1;
                int tmp = a * b + product[answer_index]; 
                product[answer_index] = tmp % 10;
                product[answer_index - 1] += tmp / 10; 
            }
        }
        
        int id = 0;
        while(product[id] == 0) id++;
        
        string ans = "";
        for (int i = id; i < product.size(); ++i) {
            ans += product[i] + '0';
        }
        
        return ans;
    }
};

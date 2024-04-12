// original method with O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int total_sum = 0;
        
        // normal flow.
        int temp_sum = 0; // for open case.
        for (int i = 0; i < height.size(); ++i) {
            if (height[left] <= height[i]) {
                total_sum += temp_sum;
                temp_sum = 0;
                left = i;
            } else {
                temp_sum += height[left] - height[i];
            }
        }
        
        // In the end, check whether this is a open case.
        if (temp_sum != 0) {
            temp_sum = 0;
            int old_left = left; 
            left = height.size()-1;
            for (int i = height.size()-1; i >= old_left; --i) {
                if (height[left] <= height[i]) {
                    total_sum += temp_sum;
                    temp_sum = 0;
                    left = i;
                } else {
                    temp_sum += height[left] - height[i];
                }
            }
        }
        
        return total_sum;
    }
};

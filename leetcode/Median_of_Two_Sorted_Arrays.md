# Median of Two Sorted Arrays

## straight method
merge two sorted array , got answer array
calculate median
```cpp=
class Solution {
public:
    // brute force 
    // merge two sorted , and get the median number
    // but it will use O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer(nums1.size()+nums2.size(), 0);
        int n1 = 0, n2 = 0, a = 0;
        while (n1 < nums1.size() && n2 < nums2.size()) {
            if (nums1[n1] < nums2[n2]) 
                answer[a++] = nums1[n1++];
            else if (nums1[n1] > nums2[n2])
                answer[a++] = nums2[n2++];
            else {
                // remoind that duplicate case can not be ignore! !
                answer[a++] = nums1[n1];
                answer[a++] = nums1[n1];
                n1++; n2++;
            }
        }
        while (n1 < nums1.size()) 
            answer[a++] = nums1[n1++];
        while (n2 < nums2.size()) 
            answer[a++] = nums2[n2++];
    
        int middle = answer.size()-1;
        if (middle % 2) 
            return ((double)(answer[middle/2] + answer[middle/2 + 1])/2);
        else 
            return (double)(answer[middle/2]);    
    }
    
};
```


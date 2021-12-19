class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> new1;
        new1.assign(nums1.begin(), nums1.begin()+m);
        
        int p1 = 0, p2 = 0, p = 0;
        
        while(p1 < m && p2 < n) {
            if (new1[p1] < nums2[p2]) {
                nums1[p++] = new1[p1++];
            } else if (new1[p1] > nums2[p2]) {
                nums1[p++] = nums2[p2++];
            } else {
                if (p1 <= p2) {
                    nums1[p++] = new1[p1++];
                } else {
                    nums1[p++] = nums2[p2++];
                }
            }
        }
        
        while(p1 < m) {
            nums1[p++] = new1[p1++];
        }
        while(p2 < n) {
            nums1[p++] = nums2[p2++];
        }
        
    }
};

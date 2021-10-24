/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let start = 0
    let end = height.length-1
    let ans = 0
    
    while (start < end) {
        ans = Math.max(ans, Math.min(height[start], height[end]) * (end - start)) 
        if (height[start] < height[end]) {
            start ++
        } else {
            end--
        }
    }
    return ans
};

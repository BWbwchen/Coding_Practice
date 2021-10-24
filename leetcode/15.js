/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort(function(a, b) {
      if (a > b) return 1;
      if (a < b) return -1;
      return 0;
    })
    
    let ans = []
    
    let i = 0
    while (i < nums.length) {
        let goal = -nums[i]
        let l = i + 1
        let r = nums.length - 1
        
        while (l < r) {
            if (nums[l] + nums[r] < goal) {
                l++
            } else if (nums[l] + nums[r] > goal) {
                r--
            } else if (nums[l] + nums[r] === goal){
                ans.push([nums[i], nums[l], nums[r]]) 
                l++
                r--
                while(l < r && (nums[l-1] === nums[l])) l++
                while(l < r && (nums[r] === nums[r+1])) r--
            }
        }
        i++ 
        while(i < nums.length && (nums[i-1] === nums[i])) i++
    }
    return ans
};

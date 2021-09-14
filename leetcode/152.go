func maxProduct(nums []int) int {
    if len(nums) == 0 {
        return 0;
    }
    
    dp_max := nums[0]
    dp_min := nums[0]
    ans := dp_max;
    
    for i := 1; i < len(nums); i++ {
        num := nums[i]
        pre_dp_max := dp_max
        dp_max =  max(max(num, num*dp_max), num*dp_min)
        dp_min =  min(min(num, num*pre_dp_max), num*dp_min)
        ans = max(ans, dp_max)
    }
    return ans 
}

func max (a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min (a, b int) int {
    if a < b {
        return a
    }
    return b
}

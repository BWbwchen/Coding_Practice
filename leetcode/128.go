func longestConsecutive(nums []int) int {
    us := map[int]bool{}
    for _, num := range nums {
        us[num] = true
    }
    
    var ans int = 0
    
    for key, _ := range us {
        if _, exist := us[key-1]; !exist {
            startTarget := key
            currentLen := 1
            
            for  {
                _, ok := us[startTarget+1]
                if !ok {
                    break
                }
                startTarget ++
                currentLen ++
            }
            
            ans = max(ans, currentLen);
        }
    }
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

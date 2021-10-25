/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) {
    let dp = new Array(s.length)
    let ret = [] 
    
    for (let i = 0; i < s.length; ++i) {
        dp[s[i].charCodeAt(0) - 97] = i
    }
    
    let temp_end = 0, anchor = 0
    for (let i = 0; i < s.length; ++i) {
        temp_end = Math.max(temp_end, dp[s[i].charCodeAt(0)-97]) 
        if (temp_end === i) {
            ret.push(i-anchor+1)
            anchor = i + 1
        }
        
    }
    return ret
};

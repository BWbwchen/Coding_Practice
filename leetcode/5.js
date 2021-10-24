/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let dp = new Array(s.length+1).fill().map(entry => new Array(s.length+1).fill(0)) 
    
    for (let i = 0; i <= s.length; ++i) {
        dp[i][i] = 1;
    }
    
    for (let i = 1; i < s.length; ++i) {
        if (s[i-1] === s[i]) {
            dp[i][i+1] = 2
        }
    }
    
    for (let j = 3; j <= s.length; ++j) {
        for (let i = 1; i <= j-2; ++i) {
            if (s[i-1] === s[j-1] && dp[i+1][j-1] != 0) {
                dp[i][j] = dp[i+1][j-1] + 2 
            }
        }
    }
    
    let ans = 0
    let as = ""
    for (let i = 1; i <= s.length; ++i) {
        for (let j = i; j <= s.length; ++j) {
            if (dp[i][j] > ans) {
                ans = dp[i][j]
                as = s.slice(i-1, i-1+ans)
            }
        }
    }
    return as
};

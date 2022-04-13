impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        if s.len() == 0 {
            return 1;
        }

        let s = s.as_bytes();

        let mut dp = vec![0; s.len() + 1];

        dp[0] = 1;
        dp[1] = match s[0] {
            b'0' => 0,
            _ => 1,
        };

        let probe = |bit1: u8, bit2: u8| {
            let n = (bit1 - b'0') * 10 + (bit2 - b'0');
            9 < n && n < 27
        };

        for i in 2..s.len() + 1 {
            if s[i - 1] != b'0' {
                dp[i] += dp[i - 1];
            }

            if probe(s[i - 2], s[i - 1]) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.len()];
    }
}

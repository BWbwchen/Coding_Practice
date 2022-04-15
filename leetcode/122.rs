use std::cmp::max;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit: i32 = 0;

        for i in 0..prices.len() - 1 {
            profit += max(prices[i + 1] - prices[i], 0);
        }

        profit
    }
}

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();

        for i in 0..num_rows as usize {
            let mut tmp: Vec<i32> = vec![1; i + 1];
            for j in 1..i {
                tmp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push(tmp);
        }

        ans
    }
}

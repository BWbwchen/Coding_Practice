impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();

        use std::cmp::max;

        nums.iter()
            .zip(nums.iter().rev())
            .fold(i32::MIN, |acc, (&a, &b)| max(acc, a + b))
    }
}

impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let mut map = [0; 100001];

        use std::cmp;
        let (min, max) = nums
            .iter()
            // (min, max)
            .fold((i32::MAX, i32::MIN), |acc, &x| {
                map[x as usize] += 1;
                (cmp::min(acc.0, x), cmp::max(acc.1, x))
            });

        // two pointer
        let (mut l, mut r) = (min, max);
        let mut ans = i32::MIN;
        while l < r {
            if map[l as usize] == 0 {
                l += 1;
            } else if map[r as usize] == 0 {
                r -= 1;
            } else {
                ans = cmp::max(ans, l + r);
                let common_min = cmp::min(map[l as usize], map[r as usize]);
                map[l as usize] -= common_min;
                map[r as usize] -= common_min;
            }
        }

        if map[l as usize] > 0 {
            ans = cmp::max(ans, 2 * l);
        }

        ans
    }
}

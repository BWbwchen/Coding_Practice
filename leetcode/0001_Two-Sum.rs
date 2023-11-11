use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

        for (i, &v) in nums.iter().enumerate() {
            let find = target - v;
            if map.contains_key(&find) {
                return vec![i as i32, map[&find]];
            }
            map.insert(v, i as i32);
        }
        unreachable!()
    }
}

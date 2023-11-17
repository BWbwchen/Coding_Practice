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

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        type TAcc = (Vec<i32>, HashMap<i32, i32>);

        let mut init = (Vec::with_capacity(2), HashMap::with_capacity(nums.len()));
        nums.iter()
            .enumerate()
            .fold(init, |mut acc, (i, &v)| {
                let find = target - v;
                if let Some(&x) = acc.1.get(&find) {
                    acc.0 = vec![i as i32, x];
                } else {
                    acc.1.insert(v, i as i32);
                }

                acc
            })
            .0
    }
}

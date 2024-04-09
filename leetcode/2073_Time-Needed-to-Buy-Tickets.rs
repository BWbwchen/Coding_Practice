impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        // O(n) algorithm
        let mut ret: i32 = 0;
        let target = *tickets.get(k as usize).unwrap();

        use std::cmp::min;
        for (i, &v) in tickets.iter().enumerate() {
            if i <= k as usize {
                ret += min(v, target);
            } else {
                ret += min(v, target - 1);
            }
        }

        ret
    }
}

impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        let mut ret = 0;
        let mut tickets = tickets.clone();

        // brute force
        'outer: loop {
            for (i, v) in tickets.iter_mut().enumerate() {
                if *v == 0 {
                    continue;
                }
                ret += 1;
                *v -= 1;
                if i as i32 == k && *v == 0 {
                    break 'outer;
                }
            }
        }

        ret
    }
}

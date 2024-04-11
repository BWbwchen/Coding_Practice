impl Solution {
    pub fn remove_kdigits(num: String, k: i32) -> String {
        use std::collections::VecDeque;
        let mut k = k;
        let mut mstack:Vec<char> = Vec::new();
        // Monolitic stack
        for n in num.chars() {
            // insert to stack
            while !mstack.is_empty() && k > 0 && *mstack.last().unwrap() > n {
                mstack.pop();
                k -= 1;
            }
            mstack.push(n);
        }

        for _ in 0..k {
            mstack.pop();
        }

        let ret = mstack.into_iter().collect::<String>().trim_start_matches('0').to_string();

        if ret.len() == 0 {
            "0".to_string()
        } else {
            ret
        }
    }
}

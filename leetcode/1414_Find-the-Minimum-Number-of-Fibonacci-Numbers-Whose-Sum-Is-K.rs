impl Solution {
    pub fn find_min_fibonacci_numbers(k: i32) -> i32 {
        let mut fib = Vec::new();
        fib.push(1);
        fib.push(1);
        let mut i = 2;

        loop {
            let f = fib.get(i-1).unwrap() + fib.get(i-2).unwrap();

            if f > k {
                break;
            }

            fib.push(f);
            i += 1;
        }

        let mut ret = 0;
        let mut k = k;
        for f in fib.iter().rev() {
            if k - f == 0 {
                ret += 1;
                break;
            } else if k - f > 0 {
                ret += 1;
                k -= f;
            } else {
                // k - f < 0
                // try smaller f
                continue;
            }
        }

        ret
    }
}

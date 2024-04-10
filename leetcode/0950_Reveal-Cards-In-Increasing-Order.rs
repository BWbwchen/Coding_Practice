impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        use std::collections::VecDeque;
        let mut deck = deck.clone();

        deck.sort();

        let mut q = VecDeque::new();

        for l in (0..deck.len()) {
            q.push_back(l);
        }

        let mut ret = deck.clone();

        for (i, v) in deck.iter().enumerate() {
            let idx = q.pop_front().unwrap();
            ret[idx] = *v;

            if !q.is_empty() {
                let front = q.pop_front().unwrap();
                q.push_back(front);
            }
        }
        ret
    }
}

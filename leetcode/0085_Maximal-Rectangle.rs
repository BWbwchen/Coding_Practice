use std::cmp::max;
impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        let mut histagram = vec![0; matrix.get(0).unwrap().len()];
        let mut ret = 0;

        for (i, row) in matrix.iter().enumerate() {
            // build histagram that begin from the first row and end at this row.
            for (j, v) in row.iter().enumerate() {
                if *v == '0' {
                    histagram[j] = 0;
                } else {
                    histagram[j] += 1;
                }
            }
            ret = max(ret, Self::get_area(&matrix, &mut histagram));
        }
        ret
    }
    fn get_area(matrix: &Vec<Vec<char>>, hist: &mut Vec<i32>) -> i32 {
        // monotonic stack with the biggest top value.
        let mut mst: Vec<(i32, i32)> = Vec::new();
        let mut ret = 0;

        hist.push(0);

        for (col, height) in hist.iter().enumerate() {
            while !mst.is_empty() && (mst.last().unwrap().1 > *height) {
                // value `height` smaller than the top, calculate the temp ans
                
                // the area is:
                // height = the height of the top element of the stack
                // width = (idx right now - 1) - the second biggest element idx.
                let prev = mst.last().unwrap_or(&(-1, 0)).clone();
                mst.pop();
                let prev_height = prev.1;
                let prev_width = col as i32 - mst.last().unwrap_or(&(-1, 0)).0 - 1;
                let tmp_area = prev_height * prev_width;
                ret = max(ret, tmp_area)
            }
            mst.push((col as i32, *height));
        }

        hist.pop();

        ret
    }
}

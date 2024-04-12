impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        // suppose that the left of an unknow sequence is the level of the water.
        let mut boundary_idx = 0;
        let mut curr_water_level = *height.first().unwrap();
        let mut ret = 0;
        let mut acc_water = 0;

        for (i, &h) in height.iter().enumerate() {
            if curr_water_level <= h {
                // we have completed a trap of water.
                println!("Accumulate {}, from {} to {}", acc_water, boundary_idx, i);
                boundary_idx = i;
                curr_water_level = h;
                ret += acc_water;
                acc_water = 0;
            } else {
                // continuously accumulate water
                acc_water += curr_water_level - h;
            }
        }

        // But in some case, the above assumption doesn't hold, we should use the other endpoint as the level of the water.
        // when `acc_water != 0`, it means that this trap of water didn't have a correct endpoint.
        if acc_water != 0 {
            acc_water = 0;
            curr_water_level = *height.last().unwrap();
            let old_boundary_idx = boundary_idx;
            boundary_idx = height.len() - 1;
            for (i, &h) in height.iter().enumerate().rev() {
                if i < old_boundary_idx {
                    break;
                }
                if curr_water_level <= h {
                    println!("*Accumulate {}, from {} back {}", acc_water, i, boundary_idx);
                    curr_water_level = h;
                    ret += acc_water;
                    acc_water = 0;
                    boundary_idx = i;
                } else {
                    acc_water += curr_water_level - h;
                }
            }
        }
        ret
    }
}

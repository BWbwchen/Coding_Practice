func rotate(nums []int, k int)  {
    _k := k % len(nums)
    reverse(nums, 0, len(nums))
    reverse(nums, 0, _k)
    reverse(nums, _k, len(nums))
}

func reverse(nums []int, start int, end int) {
    for (start != end) && (start != end-1) {
        end = end - 1
        my_swap(&nums[start], &nums[end])
        start = start + 1
    }
}

func my_swap(a *int, b *int) {
    *a, *b = *b, *a
}

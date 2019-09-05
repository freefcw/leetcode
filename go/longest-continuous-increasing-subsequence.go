package leetcode

func findLengthOfLCIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	max := 1
	current := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			current++
		} else {
			if current > max {
				max = current
			}
			current = 1
		}
	}
	if current > max {
		max = current
	}
	return max
}

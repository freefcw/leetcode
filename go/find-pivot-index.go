package leetcode

func pivotIndex(nums []int) int {
	if len(nums) == 0 {
		return -1
	}
	if len(nums) == 1 {
		return 0
	}
	sum := 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}
	left := 0
	right := sum
	for i := 0; i < len(nums); i++ {
		right = right - nums[i]
		if left == right {
			return i
		}
		left += nums[i]
	}
	return -1
}

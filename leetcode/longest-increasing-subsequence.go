package leetcode

func lengthOfLIS(nums []int) int {
	lenArr := make([]int, len(nums))

	max := 0
	for i := 0; i < len(nums); i++ {
		current := 1
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] && lenArr[j] >= current {
				current = lenArr[j] + 1
			}
		}
		lenArr[i] = current
		if current > max {
			max = current
		}
	}

	return max
}

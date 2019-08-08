package leetcode

func subarraySum(nums []int, k int) int {
	if len(nums) == 0 {
		return 0
	}
	total := 0
	length := len(nums)
	sum := make([]int, length+1)
	sum[0] = 0
	for i := 1; i < length+1; i++ {
		sum[i] = sum[i-1] + nums[i-1]
	}
	for i := 0; i < length; i++ {
		for j := i + 1; j < length+1; j++ {
			t := sum[j] - sum[i]
			// fmt.Printf("%d %d %d\n", j, i, t)
			if t == k {
				total++
			}
		}
	}

	return total
}

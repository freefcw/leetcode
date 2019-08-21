package leetcode

// https://leetcode.com/problems/combination-sum-iv/

func combinationSum4(nums []int, target int) int {
	sums := make([]int, target+1)
	sums[0] = 1
	for i := 1; i <= target; i++ {
		for _, num := range nums {
			if i-num >= 0 {
				sums[i] += sums[i-num]
			}
		}
		// fmt.Printf("sums[%d] = %d\n", i, sums[i])
	}

	return sums[target]
}

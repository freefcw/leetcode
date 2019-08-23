package leetcode

func reverseInts(nums []int, i, j int) {
	j = j - 1
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
}

func nextPermutation(nums []int) {
	first := len(nums) - 1
	for first > 0 {
		if nums[first] > nums[first-1] {
			first--
			break
		}
		first--
	}
	// switch
	target := len(nums) - 1
	for target > 0 {
		if nums[target] > nums[first] {
			break
		}
		target--
	}
	if target == 0 && first == 0 {
		reverseInts(nums, 0, len(nums))
		return
	}
	// fmt.Printf("%v %d %d\n", nums, nums[first], nums[target])
	if target < first {
		reverseInts(nums, target, len(nums))
		return
	}
	nums[target], nums[first] = nums[first], nums[target]
	reverseInts(nums, first+1, len(nums))
}

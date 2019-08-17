package leetcode

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// o(n), inplace
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	current := nums[0]
	currentCount := 1
	pos := 0
	for i := 1; i < len(nums); i++ {
		if current != nums[i] {
			nums[pos] = current
			if currentCount > 1 {
				pos++
				nums[pos] = current
			}
			current = nums[i]
			currentCount = 1
			pos++
		} else {
			currentCount++
		}
	}
	nums[pos] = current
	if currentCount > 1 {
		pos++
		nums[pos] = current
	}
	// fmt.Printf("%v\n", nums)
	return pos + 1
}

// use new array
func removeDuplicates2(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	result := make([]int, 0, len(nums))
	current := nums[0]
	currentCount := 1
	for i := 1; i < len(nums); i++ {
		if current != nums[i] {
			result = append(result, current)
			if currentCount > 1 {
				result = append(result, current)
			}
			current = nums[i]
			currentCount = 1
			continue
		}
		currentCount++
	}
	if currentCount > 0 {
		result = append(result, current)
		if currentCount > 1 {
			result = append(result, current)
		}
	}
	copy(nums, result)

	return len(result)
}

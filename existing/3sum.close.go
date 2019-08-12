package main

import (
	"fmt"
	"sort"
)

// 使用逼近方法，不用hash存结果

func strip3(nums []int) []int {
	if len(nums) == 0 {
		return nums
	}
	newnums := make([]int, 1)
	last := nums[0]
	newnums[0] = nums[0]
	count := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == last {
			count++
			if count < 3 {
				newnums = append(newnums, nums[i])
				// diffs[last] = len(newnums) - 1
			}
			if last == 0 && count == 3 {
				newnums = append(newnums, nums[i])
				// diffs[last] = len(newnums) - 1
			}
		} else {
			last = nums[i]
			count = 1
			newnums = append(newnums, nums[i])
			// diffs[last] = len(newnums) - 1
		}
	}
	return newnums
}

func threeSum(nums []int) [][]int {
	results := make([][]int, 0, 200)
	sort.Ints(nums)
	nums = strip3(nums)

	for i := 0; i+2 < len(nums); i++ {
		if nums[i] > 0 {
			break
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		low := i + 1
		high := len(nums) - 1
		for low < high {
			if nums[i]+nums[low]+nums[high] == 0 {
				results = append(results, []int{nums[i], nums[low], nums[high]})
			}
			if nums[i]+nums[low]+nums[high] <= 0 {
				for {
					low++
					if low >= high {
						break
					}
					if nums[low] != nums[low-1] {
						break
					}
				}
			}
			if nums[i]+nums[low]+nums[high] > 0 {
				for {
					high--
					if low >= high {
						break
					}
					if nums[high] != nums[high+1] {
						break
					}
				}
			}
		}
	}

	return results
}

func main() {
	data := []int{-1, 0, 1, 2, -1, -4}
	// data := []int{-1, 0, 1, 0}
	// data := []int{0, 0, 0, 0}

	fmt.Println(threeSum(data))
}

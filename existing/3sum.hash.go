package main

import (
	"fmt"
	"sort"
)

// 将差值保存在hash中，减少比对次数

var diffs map[int]int

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
	results := make([][]int, 0, 100)
	diffs = make(map[int]int)
	sort.Ints(nums)
	nums = strip3(nums)

	for i := 0; i < len(nums); i++ {
		diffs[nums[i]] = i
	}

	for i := 0; i+2 < len(nums); i++ {
		if nums[i] > 0 {
			break
		}
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j+1 < len(nums); j++ {
			if nums[j] == nums[j-1] && j-1 > i {
				continue
			}
			diff := 0 - (nums[i] + nums[j])
			if pos, ok := diffs[diff]; ok {
				if pos > j {
					// fmt.Printf("%d %d %d\n", i, j, pos)
					results = append(results, []int{nums[i], nums[j], diff})
				} else {
					break
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

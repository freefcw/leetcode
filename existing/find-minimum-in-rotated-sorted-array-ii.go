package main

import (
	"fmt"
)

func findMin(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	from := 0
	to := len(nums) - 1
	for from < to {
		// fmt.Printf("%d %d\n", from, to)
		if nums[from] < nums[to] {
			return nums[from]
		}
		if from+1 == to {
			return nums[to]
		}
		mid := (from + to) / 2
		if nums[mid] < nums[from] {
			to = mid
			continue
		}
		if nums[mid] > nums[to] {
			from = mid
			continue
		}
		if nums[mid] == nums[to] && nums[mid] == nums[from] {
			from++
			continue
		}
		if nums[mid] == nums[to] {
			to = mid
			continue
		}
		if nums[mid] == nums[from] {
			from = mid
			continue
		}
	}

	return 0
}

func main() {
	candidates := []int{3, 3, 3, 3, 3, 3, 3, 3, 1, 3}
	results := findMin(candidates)
	fmt.Println(results)

	fmt.Printf("hello world!\n")
}

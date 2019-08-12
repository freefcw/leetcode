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
	}

	return 0
}

func main() {
	candidates := []int{4, 5, 6, 7, 0, 1, 2}
	results := findMin(candidates)
	fmt.Println(results)

	fmt.Printf("hello world!\n")
}

package main

import (
	"fmt"
)

func search(nums []int, target int) bool {
	result := bs(nums, target, 0, len(nums)-1)
	return result != -1
}

func bs(nums []int, target, from, to int) int {
	if from > to {
		return -1
	}
	mid := (from + to) / 2
	result := 0
	// fmt.Printf("from %d to %d, mid %d\n", from, to, mid)
	if nums[mid] == target {
		return mid
	}
	// defabc
	if target < nums[from] && target > nums[to] {
		return -1
	}
	// abcdef
	if nums[from] < nums[to] {
		if target >= nums[from] && target < nums[mid] {
			return bs(nums, target, from, mid-1)
		}
		if target > nums[mid] && target <= nums[to] {
			return bs(nums, target, mid+1, to)
		}
		return -1
	}

	result = bs(nums, target, from, mid-1)
	if result != -1 {
		return result
	}
	return bs(nums, target, mid+1, to)
}

func main() {
	candidates := []int{2, 5, 6, 0, 0, 1, 2}
	results := search(candidates, 3)
	fmt.Println(results)

	fmt.Printf("hello world!\n")
}

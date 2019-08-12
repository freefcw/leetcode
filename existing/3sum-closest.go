package main

import (
	"fmt"
	"sort"
)

func abs(num int) int {
	if num > 0 {
		return num
	}
	return 0 - num
}

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	
	closest := nums[0] + nums[1] + nums[len(nums) - 1]
	var sum int
	for i := 0; i < len(nums) - 2; i++ {
		low := i + 1
		high := len(nums) - 1
		for low < high {
			sum = nums[i] + nums[low] + nums[high]
			if sum == target {
				return sum
			}
			if abs(sum - target) < abs(closest - target) {
				closest = sum
			}
			if sum < target {
				low++
			}
			if sum > target {
				high--
			}
		}
	}
	
    return closest
}

func main() {
	times := []int{-2, -5, 2, 1, -4}
	// times := []int{-1, 2, 1, -4}
	fmt.Println(threeSumClosest(times, 1))

	fmt.Printf("hello world!\n")
}

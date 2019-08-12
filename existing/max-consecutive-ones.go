package main

import (
	"fmt"
)

func findMaxConsecutiveOnes(nums []int) int {
	max := 0
	count := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			count++
		} else {
			if count > max {
				max = count
			}
			count = 0
		}
	}
	if count > max {
		max = count
	}

	return max
}

func main() {
	candidates := []int{1, 0, 1, 1, 1, 1}
	results := findMaxConsecutiveOnes(candidates)
	fmt.Println(results)

	fmt.Printf("hello world!\n")
}

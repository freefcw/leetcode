package main

import (
	"fmt"
)

func abs(a int) int {
	if a > 0 {
		return a
	}
	return 0 - a
}

func findDuplicates(nums []int) []int {
	twiced := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		target := abs(nums[i]) - 1
		if nums[target] < 0 {
			twiced = append(twiced, abs(nums[i]))
		} else {
			nums[target] = -(nums[target])
		}
	}

	return twiced
}

func findDuplicates2(nums []int) []int {
	for i := 0; i < len(nums); {
		target := nums[i] - 1
		if nums[target] != nums[i] {
			nums[i], nums[target] = nums[target], nums[i]
		} else {
			i++
		}
	}
	twiced := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		target := nums[i] - 1
		if target != i {
			twiced = append(twiced, target + 1)
		}
	}

	return twiced
}

func main() {

	// a := []int{4, 3, 2, 7, 8, 2, 3, 1}
	a := []int{5,4,6,7,9,3,10,9,5,6}

	fmt.Println(findDuplicates(a))

	fmt.Printf("hello world!\n")
}

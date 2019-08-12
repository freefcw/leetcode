package main

import (
	"fmt"
)

func findDisappearedNumbers(nums []int) []int {
	for i := 0; i < len(nums); {
		target := nums[i] - 1
		if nums[target] != nums[i] {
			nums[i], nums[target] = nums[target], nums[i]
		} else {
			i++
		}
	}
	missed := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		if nums[i] != i+1 {
			missed = append(missed, i+1)
		}
	}

	return missed
}

func main() {

	a := []int{4, 3, 2, 7, 8, 2, 3, 1}

	fmt.Println(findDisappearedNumbers(a))

	fmt.Printf("hello world!\n")
}

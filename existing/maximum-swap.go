package main

import (
	"fmt"
)

func parse(num int) []int {
	nums := make([]int, 0)
	for num > 0 {
		nums = append(nums, num%10)
		num = num / 10
	}
	length := len(nums)
	for i := 0; i < length-i; i++ {
		t := nums[i]
		nums[i] = nums[length-i-1]
		nums[length-i-1] = t
	}
	return nums
}

func unParse(nums []int) int {
	result := 0
	for i := 0; i < len(nums); i++ {
		result = result*10 + nums[i]
	}
	return result
}

func maximumSwap(num int) int {
	nums := parse(num)
	for i := 0; i < len(nums); i++ {
		currentMax := i
		for k := i + 1; k < len(nums); k++ {
			if nums[k] >= nums[currentMax] {
				currentMax = k
			}
		}
		if currentMax != i && nums[currentMax] > nums[i] {
			nums[currentMax], nums[i] = nums[i], nums[currentMax]
			break
		}
	}

	return unParse(nums)
}

func main() {
	// candidates := []int{1, 0, 1, 1, 1, 1}

	fmt.Println(maximumSwap(2736))
	fmt.Println(maximumSwap(9973))
	fmt.Println(maximumSwap(99388829))
	fmt.Println(maximumSwap(98368))
	fmt.Println(maximumSwap(1993))

	fmt.Printf("hello world!\n")
}

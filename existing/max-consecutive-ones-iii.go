package main

import (
	"fmt"
)

func countOnes(A []int) []int {
	nums := make([]int, 0)
	continous := 1
	for i := 1; i < len(A); i++ {
		if A[i] == A[i-1] {
			continous++
			continue
		}
		if A[i-1] != 1 {
			continous = 0 - continous
		}
		nums = append(nums, continous)
		continous = 1
	}
	if A[len(A) - 1] == 1 {
		nums = append(nums, continous)
	} else {
		nums = append(nums, 0 - continous)
	}
	return nums
}

func calc(nums []int, K int) int {
	max := 0

	negative := 0
	positive := 0
	for i := 0; i < len(nums); i++ {
		positive = 0
		negative = 0
		if nums[i] > 0 {
			positive = nums[i]
		} else {
			negative = nums[i]
		}
		if positive > max {
			max = positive
		}
		for k := i + 1; k < len(nums); k++ {
			if nums[k] > 0 {
				positive += nums[k]
			} else {
				negative += nums[k]
			}
			if positive > max {
				max = positive
			}
			if negative + K < 0 {
				if positive + K > max {
					// fmt.Printf("%d %d positive: %d\n", i, k, positive)
					max = positive + K
					// fmt.Printf("max: %d\n", max)
				}
				break
			}
		}
		if negative + K >= 0 {
			if max < positive - negative {
				max = positive - negative
				// fmt.Printf("max: %d? p: %d, n: %d\n", max, positive, negative)
			}
		} 
	}

	return max
}

func longestOnes(A []int, K int) int {
	nums := countOnes(A)
	// fmt.Println(nums)
	
	max1 := calc(nums, K)
	length := len(nums)
	for i := 0; i < length - i; i++ {
		nums[i], nums[length - i - 1] = nums[length - i - 1], nums[i]
	}
	// fmt.Println(nums)
	max2 := calc(nums, K)
	if max1 > max2 {
		return max1
	}
	return max2
}

func main() {
	var times []int
	times = []int{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}
	fmt.Println(longestOnes(times, 2), 6)

	times = []int{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}
	fmt.Println(longestOnes(times, 3), 10)
	times = []int{0,0,1,1,0,0,1,0,1,0,1,1,0,0,0,1,1,1,1}
	fmt.Println(longestOnes(times, 3), 9)
	times = []int{1,1,1,1}
	fmt.Println(longestOnes(times, 3), 4)
	times = []int{1,1,1,1,0}
	fmt.Println(longestOnes(times, 3), 5)
	times = []int{0,1,1,1,1}
	fmt.Println(longestOnes(times, 3), 5)
	times = []int{0,1,1,1,1}
	fmt.Println(longestOnes(times, 0), 4)
	times = []int{0,1,1,1,0}
	fmt.Println(longestOnes(times, 3), 5)
	times = []int{1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1}
	fmt.Println(longestOnes(times, 8), 25)
	

	fmt.Printf("hello world!\n")
}

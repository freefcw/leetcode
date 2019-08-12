package main

import (
	"fmt"
)
func longestOnes(A []int, K int) int {
	low := 0
	high := 0
	zeros := 0
	max := 0
	for {
		if high >= len(A) {
			break
		}
		if A[high] == 0 {
			zeros++
		}
		for zeros > K {
			// fmt.Printf("zeros: %d, low: %d high: %d\n", zeros, low, high)
			if A[low] == 0 {
				zeros--
			}
			low++
		}
		current := high - low + 1
		if zeros <= K && current >= max {
			max = current
		}
		// fmt.Printf("zeros: %d, low: %d high: %d max: %d\n", zeros, low, high, max)
		high++
	}
	return max
}

func main() {
	var times []int
	times = []int{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}
	fmt.Println(longestOnes(times, 2), 6)

	times = []int{0,0,1,1,0,0,1,1,1,0,1, 1,0,0,0,1,1,1,1}
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

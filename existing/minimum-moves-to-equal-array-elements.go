package main

import (
	"fmt"
)

// sum 为和， n 为数组个数, z为次数, y为最终数字
// 解方程： sum + (n - 1) * z = n * y
// 有 min + z = y
// => sum + (n - 1) * z = n * (min + z)
// => sum + nz - z = n * min + z
// => z = sum - n * min
func minMoves(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}
	sum := 0
	min := nums[0]
	for i := 0; i < n; i++ {
		sum += nums[i]
		if nums[i] < min {
			min = nums[i]
		}
	}

	return sum - n*min
}

func isReach(nums []int) bool {
	fmt.Println(nums)
	for i := 0; i < len(nums); i++ {
		if nums[0] != nums[i] {
			return false
		}
	}
	return true
}

func minMovesForce(nums []int) int {
	max := nums[0]
	for i := 0; i < len(nums); i++ {
		if nums[i] > max {
			max = nums[i]
		}
	}
	total := 0
	for {
		if isReach(nums) {
			return total
		}
		total++
		countMax := 0
		for i := 0; i < len(nums); i++ {
			if nums[i] < max {
				nums[i]++
				continue
			}
			if nums[i] == max {
				countMax++
				if countMax > 1 {
					nums[i]++
					max = nums[i]
				}
			}
		}
	}
	return total
}

func main() {
	nums := []int{1, 2147483647}

	fmt.Printf("%d\n", minMoves(nums))

	fmt.Printf("hello world!\n")
}

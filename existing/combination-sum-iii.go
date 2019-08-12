package main

import (
	"fmt"
)

var target int
var level int
var results [][]int

func combinationSum3(k int, n int) [][]int {
	results = make([][]int, 0)
	target = n
	level = k

	for i := 1; i <= 9; i++ {
		nums := make([]int, 1)
		nums[0] = i
		sum := i
		dfs(nums, sum)
	}

	return results
}

func sum(nums []int) int {
	total := 0
	for _, v := range nums {
		total += v
	}
	return total
}

func dfs(nums []int, currentSum int) {
	// fmt.Printf("%v %d\n", nums, currentSum)
	
	currentLevel := len(nums) - 1
	if level == len(nums) {
		if currentSum == target {
			nr := make([]int, level)
			copy(nr, nums)
			results = append(results, nr)
		}
		return
	}
	left := target - currentSum
	if left <= nums[currentLevel] {
		return
	}
	for i := nums[currentLevel] + 1; i <= 9; i++ {
		if i > left {
			break
		}
		nn := make([]int, len(nums)+1)
		copy(nn, nums)
		nn[len(nums)] = i
		dfs(nn, currentSum + i)
	}
}

func main() {
	fmt.Println(combinationSum3(3, 7))
	fmt.Println(combinationSum3(3, 9))
	fmt.Println(combinationSum3(1, 9))
	fmt.Println(combinationSum3(2, 9))
	fmt.Println(combinationSum3(2, 18))
	fmt.Println(combinationSum3(2, 17))

	fmt.Printf("hello world!\n")
}

package main

import (
	"fmt"
)

var results [][]int
var sets []int

func subsets(nums []int) [][]int {
	// sort.Ints(nums)
	sets = nums
	results = make([][]int, 0)
	empty := make([]int, 0)
	dfs(empty, 0)

	return results
}

func dfs(currents []int, k int) {
	if k == len(sets) {
		fmt.Println(currents)
		results = append(results, currents)
		return
	}
	currents2 := make([]int, len(currents))
	copy(currents2, currents)

	dfs(currents, k+1)

	currents2 = append(currents2, sets[k])
	dfs(currents2, k+1)
}

func main() {
	nums := []int{9, 0, 3, 5, 7}
	// subsets(nums)
	fmt.Println(subsets(nums))

	fmt.Printf("hello world!\n")
}

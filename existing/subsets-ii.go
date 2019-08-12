package main

import (
	"fmt"
	"sort"
)

var results [][]int
var sets []int

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	sets = nums
	results = make([][]int, 0)
	empty := make([]int, 0)
	dfs(empty, 0)

	return results
}

func isExist(currents []int) bool {
	for i := 0; i < len(results); i++ {
		if len(results[i]) == len(currents) {
			equal := true
			for j := 0; j < len(currents); j++ {
				if results[i][j] != currents[j] {
					equal = false
					break
				}
			}
			if equal {
				return true
			}
		}
	}
	return false
}

func dfs(currents []int, k int) {
	if k == len(sets) {
		// fmt.Println(currents)
		if isExist(currents) {
			return
		}
		results = append(results, currents)
		return
	}
	currents2 := make([]int, len(currents))
	copy(currents2, currents)

	dfs(currents, k + 1)
	
	currents2 = append(currents2, sets[k])
	dfs(currents2, k + 1)
}

func main() {
	nums := []int{1,2,2}
	// subsets(nums)
	fmt.Println(subsetsWithDup(nums))

	fmt.Printf("hello world!\n")
}

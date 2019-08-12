package main

import (
	"fmt"
	"sort"
)

var results [][]int

func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)
	results = make([][]int, 0)
	currents := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		currents[0] = nums[i]
		lefts := make([]int, 0)
		lefts = append(lefts, nums[:i]...)
		lefts = append(lefts, nums[i+1:]...)
		dfs(currents, 1, lefts)
	}

	return results
}

func dfs(currents []int, k int, lefts []int) {
	// fmt.Printf("%v %v\n", currents, lefts)
	if len(lefts) == 0 {
		nc := make([]int, len(currents))
		copy(nc, currents)
		results = append(results, nc)
		return
	}

	for i := 0; i < len(lefts); i++ {
		if i > 0 && lefts[i] == lefts[i-1] {
			continue
		}
		currents[k] = lefts[i]
		nlefts := make([]int, 0)
		nlefts = append(nlefts, lefts[:i]...)
		nlefts = append(nlefts, lefts[i+1:]...)
		dfs(currents, k+1, nlefts)
	}
}

func main() {

	a := []int{1, 1,1,2,2}

	fmt.Println(permuteUnique(a))


	fmt.Printf("hello world!\n")
}

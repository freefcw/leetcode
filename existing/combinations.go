package main

import (
	"fmt"
)

var results [][]int
var maxLevel int
var toN int

func combine(n int, k int) [][]int {
	toN = n
	maxLevel = k
	results = make([][]int, 0)

	nn := make([]int, maxLevel)
	for i := 1; i <= n - k + 1; i++ {
		nn[0] = i
		dfs(nn, 1)
	}
	return results
}

func dfs(currents []int, level int) {
	// fmt.Printf("level %d, %v\n", level, currents)
	if level == maxLevel {
		nc := make([]int, maxLevel)
		copy(nc, currents)
		results = append(results, nc)
		return
	}

	last := currents[level - 1]

	for i := last + 1; i <= toN - maxLevel + level + 1; i++ {
		currents[level] = i
		dfs(currents, level + 1)
	}
}

func main() {

	fmt.Println(combine(4, 2))


	fmt.Printf("hello world!\n")
}

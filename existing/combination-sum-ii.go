package main

import (
	"fmt"
	"sort"
)

var allCandidates []int
var solutions [][]int

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	allCandidates = candidates

	solutions = make([][]int, 0)
	currents := make([]int, 0)
	dfs(currents, target, 0)

	return solutions
}

func isSame(a []int, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func dfs(currents []int, left int, from int) {
	// fmt.Printf("Level: %d %d %d %v\n", len(currents), left, from, currents)
	if left == 0 {
		for i := 0; i < len(solutions); i++ {
			if isSame(currents, solutions[i]) {
				return
			}
		}
		newSolution := make([]int, len(currents))
		copy(newSolution, currents)
		solutions = append(solutions, newSolution)
		return
	}

	for i := from; i < len(allCandidates); i++ {
		if i > 0 && i != from && allCandidates[i] == allCandidates[from] {
			continue
		}
		if left >= allCandidates[i] {
			newCurrents := append(currents, allCandidates[i])
			dfs(newCurrents, left-allCandidates[i], i+1)
		}
	}
}

func main() {
	candidates := []int{10, 1, 2, 7, 6, 1, 5}
	results := combinationSum2(candidates, 8)
	fmt.Println(results)

	fmt.Printf("hello world!\n")
}

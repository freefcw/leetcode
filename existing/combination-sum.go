package main

import (
	"fmt"
)

var allCandidates []int
var solutions [][]int

func combinationSum(candidates []int, target int) [][]int {
	allCandidates = candidates
	solutions = make([][]int, 0)
	currents := make([]int, 0)
	dfs(currents, target, 0)

	return solutions
}

func dfs(currents []int, left int, from int) {
	// fmt.Printf("Level: %d %d %d %v\n", len(currents), left, from, currents)
	if left == 0 {
		newSolution := make([]int, len(currents))
		copy(newSolution, currents)
		solutions = append(solutions, newSolution)
		return
	}

	for i := from; i < len(allCandidates); i++ {
		if left >= allCandidates[i] {
			newCurrents := append(currents, allCandidates[i])
			dfs(newCurrents, left-allCandidates[i], i)
		}
	}
}

func main() {
	candidates := []int{7, 3, 2}
	results := combinationSum(candidates, 18)
	fmt.Println(results)

	fmt.Printf("hello world!\n")
}

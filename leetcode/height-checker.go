package leetcode

import "sort"

func heightChecker(heights []int) int {
	sortedHeights := make([]int, len(heights))
	copy(sortedHeights, heights)
	sort.Ints(sortedHeights)
	count := 0

	for i := 0; i < len(heights); i++ {
		if sortedHeights[i] != heights[i] {
			count++
		}
	}

	return count
}

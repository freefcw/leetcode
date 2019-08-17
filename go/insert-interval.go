package leetcode

func isAdjacent(a []int, b []int) bool {
	if a[0] <= b[1] && a[1] >= b[0] {
		return true
	}
	return false
}

func insert(intervals [][]int, newInterval []int) [][]int {
	result := make([][]int, 0, len(intervals))
	if len(intervals) == 0 {
		result = append(result, newInterval)
		return result
	}

	inserted := false
	for i := 0; i < len(intervals); i++ {
		if isAdjacent(newInterval, intervals[i]) {
			// fmt.Printf("merge! %v %v\n", newInterval, intervals[i])
			if intervals[i][0] < newInterval[0] {
				newInterval[0] = intervals[i][0]
			}
			if intervals[i][1] > newInterval[1] {
				newInterval[1] = intervals[i][1]
			}
		} else {
			if !inserted && newInterval[1] < intervals[i][0] {
				result = append(result, newInterval)
				result = append(result, intervals[i])
				inserted = true
			} else {
				result = append(result, intervals[i])
			}
		}
	}
	if !inserted {
		result = append(result, newInterval)
	}

	return result
}

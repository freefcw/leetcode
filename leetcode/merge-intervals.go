package leetcode

func qsort(intervals [][]int, low, high int) {
	if low >= high {
		return
	}
	base := intervals[low][0]

	i := low + 1
	j := high - 1
	for {
		for i <= j && intervals[i][0] < base {
			i++
		}
		for i <= j && intervals[j][0] >= base {
			j--
		}
		if i >= j {
			break
		}
		// fmt.Printf("i %d j %d\n", i, j)
		intervals[i], intervals[j] = intervals[j], intervals[i]
	}
	intervals[j], intervals[low] = intervals[low], intervals[j]
	qsort(intervals, low, j)
	qsort(intervals, j+1, high)
}

func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 {
		return intervals
	}
	qsort(intervals, 0, len(intervals))
	result := make([][]int, 0, len(intervals))
	last := make([]int, 2)
	last[0], last[1] = intervals[0][0], intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		if isAdjacent(last, intervals[i]) {
			// fmt.Printf("merge! %v %v\n", last, intervals[i])
			if last[1] < intervals[i][1] {
				last[1] = intervals[i][1]
			}
		} else {
			result = append(result, last)
			last = intervals[i]
		}
	}
	result = append(result, last)

	return result
}

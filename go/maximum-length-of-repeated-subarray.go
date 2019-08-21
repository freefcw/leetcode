package leetcode

func findLength(A []int, B []int) int {
	rec := make([][]int, len(A)+1)
	for i := 0; i < len(A)+1; i++ {
		rec[i] = make([]int, len(B)+1)
	}

	max := 0
	endA := len(A) - 1
	endB := len(B) - 1
	for i := endA; i >= 0; i-- {
		for j := endB; j >= 0; j-- {
			if B[j] == A[i] {
				rec[i][j] = rec[i+1][j+1] + 1
				if rec[i][j] > max {
					max = rec[i][j]
				}
			}
		}
	}
	return max
}

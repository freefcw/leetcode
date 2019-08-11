package leetcode

import (
	"strings"
)

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := 0; i < m+1; i++ {
		dp[i] = make([]int, n+1)
	}
	for _, s := range strs {
		count0 := strings.Count(s, "0")
		count1 := len(s) - count0
		if count0 > m || count1 > n {
			continue
		}
		for i := m; i >= 0; i-- {
			if i-count0 < 0 {
				break
			}
			for j := n; j >= 0; j-- {
				if j-count1 < 0 {
					break
				}
				newSize := dp[i-count0][j-count1] + 1
				if newSize > dp[i][j] {
					dp[i][j] = newSize
				}
			}
		}
	}
	return dp[m][n]
}

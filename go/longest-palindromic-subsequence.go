package leetcode

// https://leetcode.com/problems/longest-palindromic-subsequence/

func longestPalindromeSubseq(s string) int {
	length := len(s)
	if length == 0 {
		return 0
	}
	dp := make([][]int, length)
	for i := 0; i < length; i++ {
		dp[i] = make([]int, length)
	}

	for i := 0; i < length; i++ {
		for j := 0; j < length-i; j++ {
			k := i + j
			dp[j][k] = 1
			if j == k {
				continue
			}
			if i == 1 && s[j] == s[k] {
				dp[j][j+1] = 2
				continue
			}
			max := dp[j][k-1]
			if max < dp[j+1][k] {
				max = dp[j+1][k]
			}
			if s[j] == s[k] {
				max = dp[j+1][k-1] + 2
			}
			dp[j][k] = max
		}
	}
	// for _, item := range dp {
	// 	fmt.Println(item)
	// }
	return dp[0][length-1]
}

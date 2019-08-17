package leetcode

// https://leetcode.com/problems/decode-ways/

func isValidEncode(s string) bool {
	if len(s) == 1 {
		return s >= "1" && s <= "9"
	}
	if s <= "26" && s >= "10" {
		return true
	}
	return false
}

func numDecodings(s string) int {
	if len(s) == 0 {
		return 0
	}
	dp := make([]int, len(s))
	if isValidEncode(s[0:1]) {
		dp[0] = 1
	}
	if len(s) == 1 {
		return dp[0]
	}
	for i := 1; i < len(s); i++ {
		total := 0
		if isValidEncode(s[i : i+1]) {
			total = dp[i-1]
		}
		if isValidEncode(s[i-1 : i+1]) {
			if i == 1 {
				total++
			} else {
				total = total + dp[i-2]
			}
		}
		dp[i] = total
	}

	return dp[len(s)-1]
}

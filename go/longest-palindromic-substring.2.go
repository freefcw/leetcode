package leetcode

// https://leetcode.com/problems/longest-palindromic-substring/

// use dp

func longestPalindrome2(s string) string {
	if len(s) < 1 {
		return ""
	}
	maxLen := 0
	maxStart := 0
	maxEnd := 0
	palindromeMarks := make([][]bool, len(s))
	for i := 0; i < len(s); i++ {
		palindromeMarks[i] = make([]bool, len(s))
	}
	palindromeMarks[0][0] = true
	for i := 1; i < len(s); i++ {
		palindromeMarks[i][i] = true
		if s[i-1] == s[i] {
			palindromeMarks[i][i-1] = true
			if maxLen == 0 {
				maxLen = 2
				maxStart = i - 1
				maxEnd = i
			}
		}
	}
	for i := 1; i < len(s); i++ {
		for j := 0; j < i; j++ {
			if palindromeMarks[i-1][j+1] && s[i] == s[j] {
				palindromeMarks[i][j] = true
				if i-j+1 > maxLen {
					maxLen = i - j + 1
					maxStart = j
					maxEnd = i
				}
			}

			// if palindromeMarks[i][j] {
			// 	fmt.Printf("%d:%d* ", i, j)
			// } else {
			// 	fmt.Printf("%d:%d  ", i, j)
			// }
		}
		// fmt.Println()
	}

	// fmt.Printf("len %d, i %d, j %d\n", maxLen, maxStart, maxEnd)
	if maxLen == 0 {
		return s[0:1]
	}
	return s[maxStart : maxEnd+1]
}

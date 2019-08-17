package leetcode

// https://leetcode.com/problems/longest-palindromic-substring/

func findPalindrome(s string, i int) int {
	if s[i] == s[i-1] {
		return i - 1
	}
	if i-2 >= 0 && s[i] == s[i-2] {
		return i - 2
	}
	return -1
}

func isPalindrome(s string) bool {
	if len(s) < 2 {
		return false
	}
	i := 0
	j := len(s) - 1
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

func longestPalindrome(s string) string {
	if len(s) < 1 {
		return ""
	}
	maxLen := 0
	maxPos := 0
	lens := make([]int, len(s))
	lens[0] = -1
	for i := 1; i < len(s); i++ {
		lens[i] = -1
		front := lens[i-1]
		if front == -1 {
			lens[i] = findPalindrome(s, i)
			// fmt.Printf("0, %d %d\n", i, lens[i])
		} else {
			if front > 0 && s[i] == s[front-1] {
				lens[i] = front - 1
				for {
					if lens[i] > 0 && lens[lens[i]] >= 0 {
						if isPalindrome(s[lens[lens[i]] : i+1]) {
							lens[i] = lens[lens[i]]
						} else {
							break
						}
					} else {
						break
					}
				}
			} else {
				s2 := s[front : i+1]
				// fmt.Printf("2, %d %d[%s]", front, i, s2)
				if isPalindrome(s2) {
					lens[i] = front
				}
			}
		}
		if lens[i] == -1 {
			lens[i] = findPalindrome(s, i)
		}
		newLen := i - lens[i] + 1
		if lens[i] > -1 && newLen > maxLen {
			maxLen = newLen
			maxPos = i
		}
		// fmt.Printf("i: %d, lens[i]:%d, maxLen: %d\n", i, lens[i], maxLen)
	}

	if maxLen == 0 {
		return s[0:1]
	}
	// fmt.Printf("ret %d %d %v\n", maxPos, lens[maxPos], lens)
	return s[lens[maxPos] : maxPos+1]
}

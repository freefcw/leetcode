package leetcode

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	flags := make([]bool, 256)
	maxLen := 1
	currentStart := 0
	for i := 0; i < len(s); i++ {
		key := s[i]
		if !flags[key] {
			flags[key] = true
			continue
		}
		if i-currentStart > maxLen {
			maxLen = i - currentStart
		}
		for currentStart < i {
			if s[currentStart] == s[i] {
				currentStart++
				break
			}
			key := s[currentStart]
			flags[key] = false
			currentStart++
		}
	}
	if len(s)-currentStart > maxLen {
		maxLen = len(s) - currentStart
	}

	return maxLen
}

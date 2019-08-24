package leetcode

func ccCountChars(s string) []byte {
	charCount := make([]byte, 27)
	for i := 0; i < len(s); i++ {
		charCount[s[i]-'a']++
	}
	return charCount
}

func commonChars(A []string) []string {
	charCount := ccCountChars(A[0])

	for k := 1; k < len(A); k++ {
		currentCount := ccCountChars(A[k])
		for i := 0; i < len(currentCount); i++ {
			if currentCount[i] < charCount[i] {
				charCount[i] = currentCount[i]
			}
		}
	}

	result := make([]string, 0, 12)
	for i := 0; i < len(charCount); i++ {
		if charCount[i] > 0 {
			var j byte
			for j = 0; j < charCount[i]; j++ {
				result = append(result, string('a'+byte(i)))
			}
		}
	}

	return result
}

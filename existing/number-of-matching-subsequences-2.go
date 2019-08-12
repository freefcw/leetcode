package main

import (
	"fmt"
)

// 暴力居然最快。。。数据设置不好
func isSubSeq(S string, a string) bool {
	j := 0
	for i := 0; i < len(S); i++ {
		if S[i] == a[j] {
			j++
		}
		if j >= len(a) {
			return true
		}
	}
	return false
}

func numMatchingSubseq(S string, words []string) int {
	wordCount := make(map[string]int)
	for _, word := range words {
		wordCount[word]++
	}
	total := 0
	for word, count := range wordCount {
		if isSubSeq(S, word) {
			total += count
		}
	}

	return total
}

func main() {
	ss := []string{"a", "bb", "acd", "ace", "d", "cde", "ce", "ec"}
	fmt.Println(numMatchingSubseq("abcde", ss))

	ss = []string{"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"}
	fmt.Println(numMatchingSubseq("dsahjpjauf", ss))


	fmt.Printf("hello world!\n")
}

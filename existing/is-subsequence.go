package main

import (
	"fmt"
)

func isSubsequence(s string, t string) bool {
	if len(s) > len(t) {
		return false
	}
	if len(s) == 0 {
		return true
	}
	pos := 0
	for i := 0; i < len(t); i++ {
		if t[i] == s[pos] {
			pos++
		}
		if pos == len(s) {
			return true
		}
	}
	return false
}

func main() {

	fmt.Println(isSubsequence("abc", "ahbgdc"))
	fmt.Println(isSubsequence("ace", "ahbgdc"))
	fmt.Println(isSubsequence("axc", "ahbgdc"))
	fmt.Println(isSubsequence("abc", "abc"))
	fmt.Println(isSubsequence("abcde", "abc"))

	fmt.Printf("hello world!\n")
}

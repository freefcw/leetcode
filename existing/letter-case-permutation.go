package main

import (
	"fmt"
	"unicode"
)

var results []string

func letterCasePermutation(s string) []string {
	results = make([]string, 0)
	
	dfs(s, 0)

	return results
}

func dfs(s string, k int) {
	if k == len(s) {
		// fmt.Println(s)
		results = append(results, s)
		return
	}
	if unicode.IsLetter(rune(s[k])) {
		r := rune(s[k])
		s1 := ""
		if k > 0 {
			s1 = s[:k]
		}
		s2 := ""
		if k < len(s) {
			s2 = s[k+1:]
		}
		if unicode.IsUpper(r) {
			ns := s1 + string(unicode.ToLower(r)) + s2
			dfs(ns, k + 1)
		} else {
			ns := s1 + string(unicode.ToUpper(r)) + s2
			dfs(ns, k + 1)
		}
	}
	dfs(s, k + 1)
}

func main() {
	fmt.Println(letterCasePermutation("a1b2"))
	fmt.Println(letterCasePermutation("3z4"))
	fmt.Println(letterCasePermutation("12345"))
	fmt.Println(letterCasePermutation("abc"))

	fmt.Printf("hello world!\n")
}

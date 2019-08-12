package main

import (
	"fmt"
)

var result []string

func generateParenthesis(n int) []string {
	result = make([]string, 0)
	dfs("", "", n)

	return result
}

func dfs(current string, s string, k int) {
	if k == 0 {
		result = append(result, current + s)
		return
	}
	
	dfs(current + "(", s + ")", k - 1)
	if (len(s) > 0) {
		dfs(current + ")", s[:len(s) - 1], k)
	}
}

func main() {
	fmt.Println(generateParenthesis(0))
	fmt.Println(generateParenthesis(1))
	fmt.Println(generateParenthesis(2))

	fmt.Printf("hello world!\n")
}

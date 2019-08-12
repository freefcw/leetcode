package main

import (
	"fmt"
)

var results []string
var charsMap [10][]byte

func initial() {
	charsMap[2] = []byte{'a', 'b', 'c'}
	charsMap[3] = []byte{'d', 'e', 'f'}
	charsMap[4] = []byte{'g', 'h', 'i'}
	charsMap[5] = []byte{'j', 'k', 'l'}
	charsMap[6] = []byte{'m', 'n', 'o'}
	charsMap[7] = []byte{'p', 'q', 'r', 's'}
	charsMap[8] = []byte{'t', 'u', 'v'}
	charsMap[9] = []byte{'w', 'x', 'y', 'z'}
}

func dfs(prefix, digits string) {
	if len(digits) == 0 {
		if len(prefix) > 0 {
			results = append(results, prefix)
		}
		
		return
	}
	if digits[0] == '1' || digits[0] == '0' {
		dfs(prefix, digits[1:])
	}
	
	for _, v := range charsMap[digits[0] - 48] {
		current := prefix + string(v)
		if len(digits) == 1 {
			results = append(results, current)
		} else {
			dfs(current, digits[1:])
		}
	}
}

func letterCombinations(digits string) []string {
	initial()
	results = make([]string, 0, 3 * len(digits))
	dfs("", digits)

	return results
}


func main() {
	fmt.Println(letterCombinations("10231"))
	

	fmt.Printf("hello world!\n")
}

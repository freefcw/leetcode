package main

import (
	"fmt"
	"strings"
)

func repeatedStringMatch(a string, b string) int {
	if !isAllContain(a, b) {
		return -1
	}
	dest := a
	k := 1
	for ; len(dest) < len(b); k++ {
		dest = dest + a
	}
	if strings.Contains(dest, b) {
		return k
	}
	dest += a
	if strings.Contains(dest, b) {
		return k + 1
	}

	return -1
}

func isAllContain(a string, b string) bool {
	var cmap [26]byte
	for _, v := range b {
		cmap[byte(v)-'a'] = 1
	}
	for _, v := range a {
		cmap[byte(v)-'a'] = 0
	}
	for i := 0; i < 26; i++ {
		if cmap[i] == 1 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(repeatedStringMatch("abcabcabcabc", "abac"))
	fmt.Printf("hello world!\n")
}

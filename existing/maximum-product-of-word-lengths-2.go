package main

import (
	"fmt"
	"strings"
	"sort"
)
var simplification map[string]string;

func stripAndOrder(s string) string {
	if len(s) <= 1 {
		return s
	}
	ns := strings.Split(s, "")
	sort.Strings(ns)
	// fmt.Println(ns)
	result := ns[0]
	for i := 1; i < len(ns); i++ {
		if ns[i] == ns[i-1] {
			continue
		}
		result += ns[i]
	}
	return result
}

func hasIntersect(a string, b string) bool {
	i := 0
	j := 0
	for {
		if i == len(a) || j == len(b) {
			return false
		}
		if a[i] == b[j] {
			return true
		}
		if a[i] < b[j] {
			i++
		} else {
			j++
		}
	}
	return true
}

func maxProduct(words []string) int {
	if len(words) < 2 {
		return 0
	}
	simplification = make(map[string]string, 0)
	
	for _, word := range words {
		simplification[word] = stripAndOrder(word)
	}
	max := 0
	for i := 0; i < len(words); i++ {
		iWord := simplification[words[i]]
		for j := i + 1; j < len(words); j++ {
			jWord := simplification[words[j]]
			nMax := len(words[i]) * len(words[j])
			if nMax <= max {
				continue
			}
			if hasIntersect(iWord, jWord) {
				continue
			}
			max = nMax
		}
	}

	return max
}

func main() {
	words := []string{"a","aa","aaa","aaaa"}
	fmt.Println(maxProduct(words))

	// fmt.Println(stripAndOrder("aabbcdde"))

	// fmt.Println(hasIntersect("", ""))
	// fmt.Println(hasIntersect("a", ""))
	// fmt.Println(hasIntersect("a", "a"))
	// fmt.Println(hasIntersect("a", "ab"))
	// fmt.Println(hasIntersect("ac", "ab"))
	// fmt.Println(hasIntersect("abcde", "fghi"))


	fmt.Printf("hello world!\n")
}

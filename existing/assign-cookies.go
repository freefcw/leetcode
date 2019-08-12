package main

import (
	"fmt"
	"sort"
)

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	result := 0
	posg := 0
	poss := 0
	for ;posg < len(g) && poss < len(s); {
		if g[posg] <= s[poss] {
			result++
			posg++
			poss++
			continue
		}
		if g[posg] > s[len(s) - 1] {
			break
		}
		if g[posg] > s[poss] {
			poss++
		}
	}
	return result
}

func main() {

	a := []int{1, 2, 3}
	b := []int{1, 1}

	fmt.Println(findContentChildren(a, b))


	fmt.Printf("hello world!\n")
}

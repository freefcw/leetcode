package main

import (
	"fmt"
)

func sortArrayByParity(A []int) []int {
	mark := 0
	for {
		if A[mark] & 1 == 1 {
			break
		} 
		mark++
		if mark >= len(A) {
			break
		}
	}
	ahead := mark + 1
	for ahead < len(A) {
		if A[ahead] & 1 == 0 {
			A[mark], A[ahead] = A[ahead], A[mark]
			mark++
		}
		ahead++
	}
	return A
}

func main() {
	a := []int{2,2,2,2}
	fmt.Println(sortArrayByParity(a))


	fmt.Printf("hello world!\n")
}

package main

import (
	"fmt"
)

func hasAlternatingBits(n int) bool {
	if n < 3 {
		return true
	}
	last := n % 2
	n = n >> 1
	for n > 0 {
		nBit := n % 2
		if last == nBit {
			return false
		}
		last = nBit
		n = n >> 1
	}

	return true
}

func main() {
	fmt.Println(hasAlternatingBits(5))
	fmt.Println(hasAlternatingBits(7))
	fmt.Println(hasAlternatingBits(11))
	fmt.Println(hasAlternatingBits(10))
	

	fmt.Printf("hello world!\n")
}

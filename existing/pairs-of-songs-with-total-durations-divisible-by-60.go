package main

import (
	"fmt"
)

func numPairsDivisibleBy60(time []int) int {
	total := 0
	counts := [60]int{}
	for i := 0; i < len(time); i++ {
		m := time[i] % 60
		l := (60 - m) % 60
		total += counts[l]
		counts[m]++
	}
	return total
}

func main() {
	times := []int{30, 20, 150, 100, 40}
	fmt.Println(numPairsDivisibleBy60(times))

	fmt.Printf("hello world!\n")
}

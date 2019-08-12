package main

import (
	"fmt"
)

func majorityElement(nums []int) []int {
	x := 0
	y := 0
	xFreq := 0
	yFreq := 0
	for _, v := range nums {
		if xFreq <= 0 && v != y {
			x = v
		}
		if yFreq <= 0 && v != x {
			y = v
		}
		if x != v {
			xFreq--
		} else {
			xFreq += 2
		}
		if y != v {
			yFreq--
		} else {
			yFreq += 2
		}
	}
	xFreq = 0
	yFreq = 0
	for _, v := range nums {
		if v == x {
			xFreq++
		}
		if v == y {
			yFreq++
		}
	}

	third := len(nums) / 3
	results := make([]int, 0)
	if xFreq > third {
		results = append(results, x)
	}
	if x != y && yFreq > third {
		results = append(results, y)
	}
	return results
}

func main() {
	a := []int{3,2,3}
	// a := []int{1,1,1,2,2,2,3,3}
	fmt.Println(majorityElement(a))


	fmt.Printf("hello world!\n")
}

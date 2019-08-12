package main

import (
	"fmt"
)

func parseBodyCount(x int) int {
	if x >> 7 == 0 {
		return 0
	}
	if x >> 5 == 6 {
		return 1
	}
	if x >> 4 == 14 {
		return 2
	}
	if x >> 3 == 30 {
		return 3
	}
	return -1
}

func isBody(x int) bool {
	return (x >> 6) == 2
}

func validUtf8(data []int) bool {
	pos := 0
	for {
		// fmt.Printf("pos: %d\n", pos)
		if pos == len(data) {
			return true
		}
		if pos > len(data) {
			return false
		}
		nextCount := parseBodyCount(data[pos]);
		// fmt.Printf("next: %d\n", nextCount)
		if nextCount == -1 {
			// fmt.Printf("head failed %d\n", nextCount)
			return false
		}
		pos++;
		if pos >= len(data) {
			if nextCount == 0 {
				return true
			}
			return false
		}

		for i := 0; i < nextCount; i++ {
			if pos + i >= len(data) {
				return false
			}
			if !isBody(data[pos + i]) {
				// fmt.Printf("here is no body %d\n", data[pos + i])
				return false
			}
		}
		pos += nextCount
	}

	return true
}

func main() {
	// case1 := []int{197, 130, 1}
	case1 := []int{230,136,145}
	fmt.Println(validUtf8(case1))
	

	fmt.Printf("hello world!\n")
}

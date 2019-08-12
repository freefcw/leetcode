package main

import (
	"fmt"
)

func isLongPressedName(name string, typed string) bool {
	if name == typed {
		return true
	}
	if len(name) == 0 || len(typed) == 0 {
		return false
	}
	i := 0
	j := 0
	lastChar := name[0]
	for {
		if i == len(name) && j == len(typed) {
			return true
		}
		if len(typed) == j {
			return false
		}
		// fmt.Printf("i %d, j %d\n", i, j)
		if i < len(name) && name[i] == typed[j] {
			lastChar = name[i]
			i++
			j++
			continue
		}
		if typed[j] == lastChar {
			j++
			continue
		}
		return false
	}
	return true
}

func main() {
	fmt.Println(isLongPressedName("alex", "aaleex")) // true
	fmt.Println(isLongPressedName("saeed", "ssaaedd")) // false
	fmt.Println(isLongPressedName("leelee", "lleeelee")) // true
	fmt.Println(isLongPressedName("laiden", "laiden")) // true
	fmt.Println(isLongPressedName("llllaiden", "laiden")) // false
	fmt.Println(isLongPressedName("pyplrz", "ppyypllr")) // false
	fmt.Println(isLongPressedName("vtkgn", "vttkgnn")) // true

	fmt.Printf("hello world!\n")
}

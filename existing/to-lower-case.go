package main

import (
	"fmt"
)

func toLowerCase(str string) string {
	x := make([]rune, len(str))
    for i, v := range str {
		if v >= 'A' && v <= 'Z' {
			x[i] = v - 'A' + 'a'
		} else {
			x[i] = v
		}
	}

	return string(x)
}

func main() {
	fmt.Println(toLowerCase("Hello"))
	fmt.Println(toLowerCase("LOVELY"))
	fmt.Println(toLowerCase(""))
	fmt.Println(toLowerCase("here"))

	fmt.Printf("hello world!\n")
}

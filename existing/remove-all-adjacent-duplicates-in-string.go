package main

import (
	"bytes"
	"fmt"
)

func removeDuplicates(s string) string {
	result := make([]byte, len(s))
	result[0] = s[0]
	pos := 0
	for i := 1; i < len(s); i++ {
		if i > len(s) {
			break
		}
		if s[i] == result[pos] {
			result[pos] = 0
			if pos > 0 {
				pos--
			}
		} else {
			result[pos+1] = s[i]
			pos++
		}
	}
	var buf bytes.Buffer
	for i := 0; i < len(result); i++ {
		if result[i] != 0 {
			buf.WriteByte(result[i])
		}
	}
	return buf.String()
}

func main() {
	fmt.Println(removeDuplicates("abbaca"))
	fmt.Println(removeDuplicates("abbbaca"))
	fmt.Println(removeDuplicates("aac"))
	fmt.Println(removeDuplicates("aacc"))
	fmt.Println(removeDuplicates("a"))

	fmt.Printf("hello world!\n")
}

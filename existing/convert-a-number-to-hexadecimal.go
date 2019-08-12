package main

import (
	"fmt"
	"bytes"
)

func toHexChar(n byte) byte {
	if n < 10 {
		return '0' + byte(n)
	}
	return byte(n - 10) + 'a'
}

func toHex(n int) string {
	if n == 0 {
		return "0"
	}
	num := uint32(n)
	result := make([]byte, 0)
	for num > 0 {
		m := num % 16
		result = append(result, byte(m))
		num = num / 16
	}

	var buff bytes.Buffer
	count := len(result)
	for i := 0; i < count; i++ {
		fmt.Fprintf(&buff, "%c", toHexChar(result[count - i - 1]))
	}
	return buff.String()
}

func main() {
	// for i := 0; i < 16; i++ {
	// 	fmt.Printf("%c\n", toHexChar(i))
	// }
	fmt.Println(toHex(26))
	fmt.Println(toHex(-1))
	fmt.Println(toHex(0))
	

	fmt.Printf("hello world!\n")
}

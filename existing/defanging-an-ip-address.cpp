package main

import (
	"fmt"
	"bytes"
)

func defangIPaddr(address string) string {
	bs := []byte(address)
	segments := bytes.Split(bs, []byte("."))

	return string(bytes.Join(segments, []byte("[.]")))
}

func main() {
	fmt.Println(defangIPaddr("1.1.1.1"))
	fmt.Println(defangIPaddr("255.100.50.0"))

	fmt.Printf("hello world!\n")
}

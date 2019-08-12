package main

import (
	"fmt"
)

var bitMap []uint32

func makeBits(s string) uint32 {
	var bits uint32
	for _, ch := range s {
		tBit := uint32(1 << uint32(ch - 'a'))
		bits = bits | tBit
	}
	return bits
}

func maxProduct(words []string) int {
	if len(words) < 2 {
		return 0
	}
	length := len(words)
	bitMap = make([]uint32, length)
	
	for i, word := range words {
		bitMap[i] = makeBits(word)
	}
	max := 0
	
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			if bitMap[i] & bitMap[j] == 0 {
				nMax := len(words[i]) * len(words[j])
				if nMax > max {
					max = nMax
				}
			}
		}
	}

	return max
}

func main() {
	// makeBits("bedcbaa")
	// fmt.Printf("%b\n%b\n", makeBits("bedcbaa"), makeBits("fddddff"))
	words := []string{"edadc","ebbfe","aacdde","dfe","cb","fddddff","fabca","adccac","ece","ccaf","feba","bcb","edadc","aea","bacb","acefa","fcebffd","dfeebca","bedcbaa","deaccc","abedc","dadff","eef","ddebbb","abecab","cd","abdeee","eedce","deef","dceaddd","ced","fbbf","ba","eefeda","fb","cddc","adafbf","dded","aadbf","caefbaf","ccebf","dbb","ee","dadcecc","ddbcabb","afeaa","ec","aad","efde","cbcda","cdbdafd","cddc","ecaaa","ae","cfc","bccac","cdcc","abbbf","fcdface","ddbcdc","bfebb","daed","bc","dc","ecdfc","eeb","bb","dad","caecb","fbe","bbbc","cacea","dbc","fbe","bcfffbd","aeda","cff","ddfc","ea","bdfd","ccb","cb","ae","ceabefa","dcea","cbaed","bfedf","fa","ccd","fece","bceef","acabca","dafa","fdeec","dac","cae","adeeadb","ecacc","acfe","de"}
	fmt.Println(maxProduct(words))

	// fmt.Println(stripAndOrder("aabbcdde"))


	fmt.Printf("hello world!\n")
}

package main

import (
	"fmt"
)

func gcd(i, j int) int {
	if i % j == 0 {
		return j
	}
	return gcd(j, i % j)
}

func getCommonDivisors(k int)[]int {
	divisors := make([]int, 1)
	divisors[0] = 1
	if k == 1 {
		return divisors
	}

	x := 2
	for {
		if x * x > k {
			divisors = append(divisors, k)
			return divisors
		}
		if k % x == 0 {
			divisors = append(divisors, x)
		}
		x++
	}
	return divisors
}

func isRepeat(x string, all string) bool {
	pos := 0
	length := len(x)
	for {
		if pos >= len(all) {
			return true
		}
		if x != all[pos: pos + length] {
			return false
		}
		pos = pos + length
	}
	return true
}

func gcdOfStrings(str1 string, str2 string) string {
	if len(str1) < len(str2) {
		str2, str1 = str1, str2
	}
	if str1[0:len(str2)] != str2 {
		return ""
	}
	maxCommonDivisors := gcd(len(str1), len(str2))
	allDivisors := getCommonDivisors(maxCommonDivisors)

	for i := len(allDivisors); i > 0; i-- {
		divisor := allDivisors[i-1]
		common := str1[0:divisor]
		// fmt.Printf("%s %d\n", common, divisor)
		if isRepeat(common, str1) && isRepeat(common, str2) {
			return common
		}
	}
	return ""
}

func main() {
	fmt.Println(gcdOfStrings("AAAAAA", "A"))

	fmt.Printf("hello world!\n")
}

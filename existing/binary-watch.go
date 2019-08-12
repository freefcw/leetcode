package main

import (
	"fmt"
)

var hourMap [][]int
var minuteMap [][]int

func getOneCount(a int) int {
	count := 0;
	for a != 0 {
		if a & 1 == 1 {
			count++
		}
		a = a >> 1
	}
	return count
}

func initial() {
	hourMap = make([][]int, 5)
	for i := 0; i < 12; i++ {
		countOne := getOneCount(i)
		hourMap[countOne] = append(hourMap[countOne], i)
	}
	minuteMap = make([][]int, 7)
	for i := 0; i < 60; i++ {
		countOne := getOneCount(i)
		minuteMap[countOne] = append(minuteMap[countOne], i)
	}
}

func buildTimeString(hour, minute int) string {
	return fmt.Sprintf("%d:%02d", hour, minute)
}

func readBinaryWatch(num int) []string {
	initial()
	result := make([]string, 0)
    for i := 0; i < 5; i++ {
		if num - i > 6 {
			continue
		}
		for k := 0; k <= num - i; k++ {
			if i + k != num {
				continue
			}
			for _, h := range hourMap[i] {
				for _, m := range minuteMap[k] {
					// fmt.Println(h, m)
					result = append(result, buildTimeString(h, m))
				}
			}
		}
	}
	return result
}


func main() {
	fmt.Println(readBinaryWatch(2))
	

	fmt.Printf("hello world!\n")
}

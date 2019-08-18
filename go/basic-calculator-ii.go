package leetcode

import (
	"fmt"
	"math"
	"strconv"
)

func calculate2(s string) int {
	result := 0
	operation := '+'
	stack := make([]StackItem, 0, 10)
	hasInitial := false

	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			continue
		}
		if s[i] == '+' || s[i] == '-' {
			stack = append(stack, StackItem{result, rune(s[i])})
			result = 0
			operation = '+'
			hasInitial = false
			continue
		}
		if s[i] == '*' {
			operation = '*'
			continue
		}
		if s[i] == '/' {
			operation = '/'
			continue
		}
		end := parseInt(s, i)
		num, err := strconv.Atoi(s[i : end+1])
		if err != nil {
			fmt.Printf("%s %d %d\n", s, i, end)
			panic(err)
		}
		if !hasInitial {
			result = num
			i = end
			hasInitial = true
		}
		// fmt.Printf("%d %c %d\n", result, operation, num)

		if operation == '*' {
			result *= num
		}
		if operation == '/' {
			result = int(math.Floor(float64(result) / float64(num)))
		}

		i = end
	}
	stack = append(stack, StackItem{result, '='})
	result = 0
	operation = '+'
	for _, item := range stack {
		if operation == '+' {
			result += item.number
		}
		if operation == '-' {
			result -= item.number
		}
		operation = item.operation
	}
	// fmt.Printf("%v %d\n", stack, result)
	return result
}

package leetcode

import (
	"fmt"
	"strconv"
)

type StackItem struct {
	number    int
	operation rune
}

func parseInt(s string, from int) int {
	if len(s) == 0 {
		return 0
	}
	for i := from; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			continue
		}
		return i - 1
	}

	return len(s) - 1
}

func calculate(s string) int {
	result := 0
	hasInitial := false
	operation := '+'
	stack := make([]StackItem, 0, 10)
	stackTop := 0
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			continue
		}
		if s[i] == '(' {
			item := StackItem{result, operation}
			if stackTop == len(stack) {
				stack = append(stack, item)
			} else {
				stack[stackTop] = item
			}
			stackTop++
			result = 0
			hasInitial = false
			operation = '+'
			continue
		}
		if s[i] == ')' {
			if stackTop == 0 {
				continue
			}
			stackTop--
			item := stack[stackTop]
			// fmt.Printf("%v %d\n", item, result)
			if item.operation == '+' {
				result = item.number + result
			} else {
				result = item.number - result
			}
			hasInitial = true
			continue
		}
		if s[i] == '+' {
			operation = '+'
			continue
		}
		if s[i] == '-' {
			operation = '-'
			continue
		}
		end := parseInt(s, i)
		num, err := strconv.Atoi(s[i : end+1])
		if err != nil {
			fmt.Printf("%s %d %d\n", s, i, end)
			panic(err)
		}
		// fmt.Printf("%d %c %d\n", result, operation, num)
		if hasInitial {
			if operation == '+' {
				result += num
			}
			if operation == '-' {
				result -= num
			}
		} else {
			result = num
			hasInitial = true
		}

		i = end
	}
	return result
}

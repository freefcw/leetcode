package leetcode

import (
	"testing"
)

func Test_stripLeadSpace(t *testing.T) {
	tables := []struct {
		input  string
		expect int
	}{
		{
			input:  "1",
			expect: 0,
		}, {
			input:  "    1",
			expect: 4,
		}, {
			input:  " -1",
			expect: 1,
		}, {
			input:  " +1",
			expect: 1,
		}, {
			input:  "+",
			expect: 0,
		}, {
			input:  " ",
			expect: -1,
		},
	}
	for _, item := range tables {
		actual := stripLeadSpace(item.input)
		if item.expect != actual {
			t.Errorf("expect: %d, actual %d.", item.expect, actual)
		}
	}
}

func Test_myAtoi(t *testing.T) {
	tables := []struct {
		input  string
		expect int
	}{
		{
			input:  "42",
			expect: 42,
		}, {
			input:  "    -42",
			expect: -42,
		}, {
			input:  " ",
			expect: 0,
		}, {
			input:  " +1",
			expect: 1,
		}, {
			input:  "-",
			expect: 0,
		}, {
			input:  "+",
			expect: 0,
		}, {
			input:  "ab",
			expect: 0,
		}, {
			input:  "4193 with words",
			expect: 4193,
		}, {
			input:  "words and 987",
			expect: 0,
		}, {
			input:  "-91283472332",
			expect: -1 << 31,
		}, {
			input:  "91283472332",
			expect: 1<<31 - 1,
		}, {
			input:  "2147483648",
			expect: 2147483647,
		}, {
			input:  "2147483647",
			expect: 2147483647,
		}, {
			input:  "-2147483649",
			expect: -2147483648,
		}, {
			input:  "-2147483648",
			expect: -2147483648,
		},
	}
	// fmt.Printf("%d %d %d %d\n", MAX_INT, MIN_INT, MAX_LIMIT, MIN_LIMIT)
	for _, item := range tables {
		actual := myAtoi(item.input)
		if item.expect != actual {
			t.Errorf("%s expect: %d, actual %d.", item.input, item.expect, actual)
		}
	}
}

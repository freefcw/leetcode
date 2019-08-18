package leetcode

import "testing"

func TestParseInt(t *testing.T) {
	tests := []struct {
		input  string
		from   int
		expect int
	}{
		{
			input:  "123",
			from:   0,
			expect: 2,
		}, {
			input:  "1234",
			from:   1,
			expect: 3,
		}, {
			input:  "1234 ",
			from:   1,
			expect: 3,
		}, {
			input:  "",
			from:   0,
			expect: 0,
		}, {
			input:  " 44 5",
			from:   1,
			expect: 2,
		},
	}

	for i, item := range tests {
		actual := parseInt(item.input, item.from)
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

func TestCalculate(t *testing.T) {
	tests := []struct {
		input  string
		expect int
	}{
		{
			input:  "1+1",
			expect: 2,
		}, {
			input:  "(1+1)+(2+2)",
			expect: 6,
		}, {
			input:  " 1 + 1 ",
			expect: 2,
		}, {
			input:  " 1 + (1 + 1)",
			expect: 3,
		}, {
			input:  " 2-1 + 2 ",
			expect: 3,
		}, {
			input:  "2-(5-6)",
			expect: 3,
		}, {
			input:  "(1+(4+5+2)-3)+(6+8)",
			expect: 23,
		},
	}

	for i, item := range tests {
		actual := calculate(item.input)
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

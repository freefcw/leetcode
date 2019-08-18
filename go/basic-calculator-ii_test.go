package leetcode

import "testing"

func TestCalucate2(t *testing.T) {
	tests := []struct {
		input  string
		expect int
	}{
		{
			input:  "1+1",
			expect: 2,
		}, {
			input:  "1-1",
			expect: 0,
		}, {
			input:  " 1 + 1 ",
			expect: 2,
		}, {
			input:  " 3/2 ",
			expect: 1,
		}, {
			input:  " 2-1 + 2 ",
			expect: 3,
		}, {
			input:  "3+2*2",
			expect: 7,
		}, {
			input:  " 3+5 / 2 ",
			expect: 5,
		},
	}

	for i, item := range tests {
		actual := calculate2(item.input)
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

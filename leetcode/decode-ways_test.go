package leetcode

import "testing"

func TestNumDecodings(t *testing.T) {
	tests := []struct {
		input  string
		expect int
	}{
		{
			input:  "12",
			expect: 2,
		}, {
			input:  "22",
			expect: 2,
		}, {
			input:  "226",
			expect: 3,
		}, {
			input:  "0",
			expect: 0,
		}, {
			input:  "010",
			expect: 0,
		}, {
			input:  "0010",
			expect: 0,
		}, {
			input:  "10",
			expect: 1,
		}, {
			input:  "100",
			expect: 0,
		},
	}
	for i, item := range tests {
		actual := numDecodings(item.input)
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

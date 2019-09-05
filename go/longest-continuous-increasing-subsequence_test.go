package leetcode

import "testing"

func TestFindLengthOfLCIS(t *testing.T) {
	tests := []struct {
		input  []int
		expect int
	}{
		{
			input:  []int{1, 3, 5, 4, 7},
			expect: 3,
		}, {
			input:  []int{2, 2, 2, 2, 2},
			expect: 1,
		}, {
			input:  []int{1, 3, 5, 7},
			expect: 4,
		}, {
			input:  []int{},
			expect: 0,
		},
	}
	for i, item := range tests {
		actual := findLengthOfLCIS(item.input)
		if actual != item.expect {
			t.Errorf("%d, expect %d, actual %d", i, item.expect, actual)
		}
	}
}

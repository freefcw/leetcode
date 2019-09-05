package leetcode

import "testing"

func TestPivotIndex(t *testing.T) {
	tests := []struct {
		input  []int
		expect int
	}{
		{
			input:  []int{1, 7, 3, 6, 5, 6},
			expect: 3,
		}, {
			input:  []int{1, 2, 3},
			expect: -1,
		}, {
			input:  []int{1},
			expect: 0,
		}, {
			input:  []int{},
			expect: -1,
		},
	}
	for i, item := range tests {
		actual := pivotIndex(item.input)
		if actual != item.expect {
			t.Errorf("%d, expect %d, actual %d", i, item.expect, actual)
		}
	}
}

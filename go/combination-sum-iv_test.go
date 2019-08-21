package leetcode

import "testing"

func TestCombinationSum4(t *testing.T) {
	tests := []struct {
		input  []int
		target int
		expect int
	}{
		{
			input:  []int{1, 2, 3},
			target: 4,
			expect: 7,
		}, {
			input:  []int{3, 1, 2, 4},
			target: 4,
			expect: 8,
		},
	}
	for i, item := range tests {
		actual := combinationSum4(item.input, item.target)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

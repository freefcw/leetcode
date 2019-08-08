package leetcode

import "testing"

func TestSubarraySum(t *testing.T) {
	tests := []struct {
		input  []int
		k      int
		expect int
	}{
		{
			input:  []int{1, 1, 1},
			k:      2,
			expect: 2,
		}, {
			input:  []int{1, 4, 3, 2},
			k:      5,
			expect: 2,
		}, {
			input:  []int{1},
			k:      0,
			expect: 0,
		}, {
			input:  []int{1, 2, 3},
			k:      3,
			expect: 2,
		}, {
			input:  []int{-1, -1, 1},
			k:      0,
			expect: 1,
		}, {
			input:  []int{100, 1, 2, 3, 4},
			k:      3,
			expect: 2,
		}, {
			input:  []int{28, 54, 7, -70, 22, 65, -6},
			k:      100,
			expect: 1,
		},
	}
	for _, item := range tests {
		actual := subarraySum(item.input, item.k)
		if actual != item.expect {
			t.Fatalf("%v %d, expect %d, actual %d", item.input, item.k, item.expect, actual)
		}
	}
}

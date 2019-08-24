package leetcode

import "testing"

func TestNextPermutation(t *testing.T) {
	tests := []struct {
		nums   []int
		expect []int
	}{
		{
			nums:   []int{5, 4, 3, 2, 1},
			expect: []int{1, 2, 3, 4, 5},
		}, {
			nums:   []int{1, 2, 3, 4, 5},
			expect: []int{1, 2, 3, 5, 4},
		}, {
			nums:   []int{1, 1, 5},
			expect: []int{1, 5, 1},
		}, {
			nums:   []int{1, 5, 8, 4, 7, 6, 5, 3, 1},
			expect: []int{1, 5, 8, 5, 1, 3, 4, 6, 7},
		}, {
			nums:   []int{1, 5, 8, 7, 6, 4, 3, 1},
			expect: []int{1, 6, 1, 3, 4, 5, 7, 8},
		},
	}

	for _, item := range tests {
		nextPermutation(item.nums)
		if !intsEqual(item.nums, item.expect) {
			t.Fatalf("\nexpect %v, actual %v", item.expect, item.nums)
		}
	}
}

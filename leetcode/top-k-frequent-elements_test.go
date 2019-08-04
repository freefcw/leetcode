package leetcode

import (
	"testing"
)

func Test_topKFrequent(t *testing.T) {
	tests := []struct {
		input  []int
		k      int
		expect []int
	}{
		{
			input:  []int{1, 1, 1, 2, 2, 3},
			k:      2,
			expect: []int{1, 2},
		}, {
			input:  []int{1},
			k:      1,
			expect: []int{1},
		},
	}

	for _, item := range tests {
		actual := topKFrequent(item.input, item.k)
		if !intsEqual(actual, item.expect) {
			t.Fatalf("expect %v, actual %v\n", item.expect, actual)
		}
	}
}

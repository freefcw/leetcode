package leetcode

import "testing"

func TestBstFromPreorder(t *testing.T) {
	tests := []struct {
		preorder []int
		expect   []int
	}{
		{
			preorder: []int{8, 5, 1, 7, 10, 12},
			expect:   []int{8, 5, 10, 1, 7, -1, 12},
		}, {
			preorder: []int{},
			expect:   []int{},
		}, {
			preorder: []int{8},
			expect:   []int{8},
		}, {
			preorder: []int{8, 2, 9},
			expect:   []int{8, 2, 9},
		},
	}

	for i, item := range tests {
		actual := bstFromPreorder(item.preorder)
		actualData := treeToSlice(actual, -1)
		if !intsEqual(actualData, item.expect) {
			t.Errorf("%d expect %v, actual %v", i, item.expect, actualData)
		}
	}
}

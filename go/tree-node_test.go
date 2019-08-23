package leetcode

import (
	"testing"
)

func TestTree(t *testing.T) {
	tests := []struct {
		vals []int
		x    int
	}{
		{
			vals: []int{8, 5, 10, 1, 7, -1, 12},
			x:    -1,
		}, {
			vals: []int{8},
			x:    -1,
		},
	}
	for _, item := range tests {
		root := buildTree(item.vals, item.x)
		actual := treeToSlice(root, item.x)

		if !intsEqual(actual, item.vals) {
			t.Fatalf("\nexpect %v \nactual %v\n", item.vals, actual)
		}
	}
}

package leetcode

import "testing"

func TestBuildTree(t *testing.T) {
	tests := []struct {
		inorder   []int
		postorder []int
		expect    []int
	}{
		{
			inorder:   []int{1, 2, 3, 4, 5},
			postorder: []int{2, 1, 5, 4, 3},
			expect:    []int{3, 1, 4, -1, 2, -1, 5},
		}, {
			inorder:   []int{1, 2, 3, 4},
			postorder: []int{4, 3, 2, 1},
			expect:    []int{1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4},
		}, {
			inorder:   []int{9, 3, 15, 20, 7},
			postorder: []int{9, 15, 7, 20, 3},
			expect:    []int{3, 9, 20, -1, -1, 15, 7},
		}, {
			inorder:   []int{9},
			postorder: []int{9},
			expect:    []int{9},
		}, {
			inorder:   []int{3, 9, 1},
			postorder: []int{3, 9, 1},
			expect:    []int{1, 9, -1, 3},
		}, {
			inorder:   []int{3, 2, 1},
			postorder: []int{3, 2, 1},
			expect:    []int{1, 2, -1, 3},
		},
	}

	for i, item := range tests {
		tree := ipbuildTree(item.inorder, item.postorder)
		actual := treeToSlice(tree, -1)
		if !intsEqual(item.expect, actual) {
			t.Fatalf("\n%d\nexpect %v\nactual %v", i, item.expect, actual)
		}
	}
}

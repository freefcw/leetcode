package leetcode

import "testing"

func Test_BSTIterator(t *testing.T) {
	tests := []struct {
		root   []int
		expect []int
	}{
		{
			root:   []int{7, 3, 15, -1, -1, 9, 20},
			expect: []int{3, 7, 9, 15, 20},
		},
	}

	for num, item := range tests {
		root := buildTree(item.root, -1)
		bstor := Constructor(root)
		for i := 0; i < len(item.expect); i++ {
			actual := bstor.Next()
			if actual != item.expect[i] {
				t.Fatalf("%d expect: %d actual: %d", num, item.expect[i], actual)
			}
		}
	}
}

package leetcode

import "testing"

func TestFindLength(t *testing.T) {
	tests := []struct {
		a      []int
		b      []int
		expect int
	}{
		{
			a:      []int{1, 2, 3, 2, 1},
			b:      []int{3, 2, 1, 4, 7},
			expect: 3,
		}, {
			a:      []int{1, 4, 7, 2, 1},
			b:      []int{3, 2, 1, 4, 7},
			expect: 3,
		}, {
			a:      []int{1},
			b:      []int{2},
			expect: 0,
		}, {
			a:      []int{2},
			b:      []int{2},
			expect: 1,
		},
	}

	for i, item := range tests {
		actual := findLength(item.a, item.b)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

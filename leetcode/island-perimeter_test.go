package leetcode

import "testing"

func TestIslandPerimeter(t *testing.T) {
	tests := []struct {
		grid   [][]int
		expect int
	}{
		{
			grid: [][]int{{0, 1, 0, 0},
				{1, 1, 1, 0},
				{0, 1, 0, 0},
				{1, 1, 0, 0}},
			expect: 16,
		}, {
			grid:   [][]int{},
			expect: 0,
		}, {
			grid:   [][]int{{0, 1}},
			expect: 4,
		}, {
			grid:   [][]int{{1, 1}},
			expect: 6,
		}, {
			grid: [][]int{{0, 0, 0, 0},
				{0, 0, 0, 0},
				{0, 0, 0, 0},
				{1, 0, 0, 0}},
			expect: 4,
		},
	}

	for i, item := range tests {
		actual := islandPerimeter(item.grid)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}

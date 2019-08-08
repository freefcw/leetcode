package leetcode

import "testing"

func Test_maxAreaOfIsland(t *testing.T) {
	tests := []struct {
		input  [][]int
		expect int
	}{
		{
			input: [][]int{
				[]int{0, 0, 0, 0, 0, 0, 0, 0},
			},
			expect: 0,
		}, {
			input: [][]int{
				[]int{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
				[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
				[]int{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
				[]int{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
				[]int{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
				[]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
				[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
			},
			expect: 6,
		}, {
			input: [][]int{
				[]int{1, 1, 0, 0, 0},
				[]int{1, 1, 0, 0, 0},
				[]int{0, 0, 0, 1, 1},
				[]int{0, 0, 0, 1, 1},
			},
			expect: 4,
		},
	}
	for index, item := range tests {
		actual := maxAreaOfIsland(item.input)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d", index, item.expect, actual)
		}
	}
}

package leetcode

import "testing"

func Test_rotate(t *testing.T) {
	tests := []struct {
		input  [][]int
		expect [][]int
	}{
		{
			input: [][]int{
				[]int{1, 2, 3},
				[]int{4, 5, 6},
				[]int{7, 8, 9},
			}, expect: [][]int{
				[]int{7, 4, 1},
				[]int{8, 5, 2},
				[]int{9, 6, 3},
			},
		}, {
			input: [][]int{
				[]int{1},
			}, expect: [][]int{
				[]int{1},
			},
		}, {
			input: [][]int{
				[]int{5, 1, 9, 11},
				[]int{2, 4, 8, 10},
				[]int{13, 3, 6, 7},
				[]int{15, 14, 12, 16},
			}, expect: [][]int{
				[]int{15, 13, 2, 5},
				[]int{14, 3, 4, 1},
				[]int{12, 6, 8, 9},
				[]int{16, 7, 10, 11},
			},
		}, {
			input: [][]int{
				[]int{1, 2, 3, 4, 5},
				[]int{6, 7, 8, 9, 10},
				[]int{11, 12, 13, 14, 15},
				[]int{16, 17, 18, 19, 20},
				[]int{21, 22, 23, 24, 25},
			}, expect: [][]int{
				[]int{21, 16, 11, 6, 1},
				[]int{22, 17, 12, 7, 2},
				[]int{23, 18, 13, 8, 3},
				[]int{24, 19, 14, 9, 4},
				[]int{25, 20, 15, 10, 5},
			},
		},
	}
	for _, item := range tests {
		rotate(item.input)
		for i := 0; i < len(item.input); i++ {
			for j := 0; j < len(item.input[i]); j++ {
				if item.input[i][j] != item.expect[i][j] {
					t.Fatalf("expect %v, actual %v", item.expect, item.input)
				}
			}
		}
	}
}

package leetcode

import "testing"

func TestFloodFill(t *testing.T) {
	tests := []struct {
		image    [][]int
		sr       int
		sc       int
		newColor int
		expect   [][]int
	}{
		{
			image:    [][]int{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
			sr:       1,
			sc:       1,
			newColor: 2,
			expect:   [][]int{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}},
		}, {
			image:    [][]int{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
			sr:       2,
			sc:       2,
			newColor: 2,
			expect:   [][]int{{1, 1, 1}, {1, 1, 0}, {1, 0, 2}},
		}, {
			image:    [][]int{{0, 0, 0}, {0, 1, 1}},
			sr:       1,
			sc:       1,
			newColor: 1,
			expect:   [][]int{{0, 0, 0}, {0, 1, 1}},
		},
	}

	for i, item := range tests {
		actual := floodFill(item.image, item.sr, item.sc, item.newColor)
		if len(actual) != len(item.expect) {
			t.Fatalf("%d failed, actual %v\n", i, actual)
		}
		for i := 0; i < len(actual); i++ {
			for j := 0; j < len(actual[0]); j++ {
				if actual[i][j] != item.expect[i][j] {
					t.Fatalf("%d expect %v, actual %v\n", i, item.expect, actual)
				}
			}
		}

	}
}

package leetcode

import "testing"

func Test_numIsLands(t *testing.T) {
	tables := []struct {
		input  [][]byte
		expect int
	}{
		{
			input: [][]byte{
				[]byte{'1', '1', '1', '1', '0'},
				[]byte{'1', '1', '0', '1', '0'},
				[]byte{'1', '1', '0', '0', '0'},
				[]byte{'0', '0', '0', '0', '0'},
			},
			expect: 1,
		}, {
			input: [][]byte{
				[]byte{'1', '1', '0', '0', '0'},
				[]byte{'1', '1', '0', '0', '0'},
				[]byte{'0', '0', '1', '0', '0'},
				[]byte{'0', '0', '0', '1', '1'},
			},
			expect: 3,
		},
	}
	for _, item := range tables {
		actual := numIslands(item.input)
		if actual != item.expect {
			t.Errorf("expect %d, actual %d\n", item.expect, actual)
		}
	}
}
